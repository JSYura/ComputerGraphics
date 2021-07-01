// Generate a procedural planet and orbiting moon. Use layers of (improved)
// Perlin noise to generate planetary features such as vegetation, gaseous
// clouds, mountains, valleys, ice caps, rivers, oceans. Don't forget about the
// moon. Use `animation_seconds` in your noise input to create (periodic)
// temporal effects.
//
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
out vec3 color;
// expects: model, blinn_phong, bump_height, bump_position,
// improved_perlin_noise, tangent
vec3 normal_map(vec3 p){
	vec3 T, B;
	tangent(p, T, B);
	vec3 n = normalize(
	cross((bump_position(is_moon, p + 0.0001 * T) - bump_position(is_moon, p)) / 0.0001,
	(bump_position(is_moon, p + 0.0001 * B)-bump_position(is_moon, p)) / 0.0001));
  return dot(p, n) <= 0 ? -n: n;
}


void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
//   color = vec3(1,1,1);

  vec3 ka, kd, ks, n, v, l;
  float p;
  mat4 mat_rot = mat4(
        cos(animation_seconds * M_PI / 2.0), 0, sin(animation_seconds * M_PI / 2.0), 0,
        0, 1.0, 0, 0,
        -sin(animation_seconds * M_PI / 2.0), 0, cos(animation_seconds * M_PI / 2.0), 0,
        0, 0, 0, 1.0);

  vec3 new_sphere_fs_in = normal_map(sphere_fs_in);
  mat4 inv_tra_m = inverse(transpose(view * model(is_moon, animation_seconds)));
  n = normalize((inv_tra_m * vec4(new_sphere_fs_in.xyz, 1.0)).xyz);
  v = ((view * view_pos_fs_in).xyz);
  l = ((view * mat_rot * vec4(1, 1, 0, 0))).xyz;

  p = 500;
  ka = vec3(0.05);
  kd = vec3(0.5);
  if (!is_moon) {
    p = 1000;
    float time = abs(sphere_fs_in.y) / (animation_seconds - 1);
    if (time <= 1 && bump_height(is_moon, sphere_fs_in) <= 10){
      ka = vec3(0.05);
      kd = vec3(0.2, 0.3, 0.5);
      ks = vec3(0.77);
    } else {
     ka = vec3(0.08);
     kd = vec3(1 - abs(sphere_fs_in.y), 1.2, 0.09);
     ks = vec3(1);
    }
  }
  float noise = abs(
  sin(0.8 * improved_perlin_noise(sphere_fs_in * vec3(1, 1, 0)) + 0.1 * improved_perlin_noise(sphere_fs_in * 10)));
  color = blinn_phong(ka, kd, ks, p, n, v, l);
  if(!is_moon){
    float noise = improved_perlin_noise(
    vec3(sphere_fs_in.x + animation_seconds * 0.4, sphere_fs_in.y,
    sphere_fs_in.z + animation_seconds) * vec3(0.3, 4, 0.5));
    float alpha = 0.12 * (smooth_heaviside(noise+0.29, 11.5) + 0.9) * min(animation_seconds, 1);
    color = (1 - alpha) * color + alpha * vec3(0.8);
  }
  /////////////////////////////////////////////////////////////////////////////
}
