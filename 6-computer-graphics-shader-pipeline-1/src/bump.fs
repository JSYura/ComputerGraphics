// Set the pixel color using Blinn-Phong shading (e.g., with constant blue and
// gray material color) with a bumpy texture.
// 
// Uniforms:
uniform mat4 view;
uniform mat4 proj;
uniform float animation_seconds;
uniform bool is_moon;
// Inputs:
//                     linearly interpolated from tessellation evaluation shader
//                     output
in vec3 sphere_fs_in;
in vec3 normal_fs_in;
in vec4 pos_fs_in; 
in vec4 view_pos_fs_in; 
// Outputs:
//               rgb color of this pixel
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
  p = 250;
  ka = vec3(0.04);
  kd = vec3(0.52);
  ks = vec3(0.85);
  if (!is_moon){
      p = 1500;
      ka = vec3(0.02, 0.02, 0.16);
      kd = vec3(0.25, 0.25, 0.8);
      ks = vec3(0.98);
     }


  float noise = abs(
  M_PI * (
  0.7 * improved_perlin_noise(sphere_fs_in * vec3(1, 1, 2) * (vec3(5, 5, 5)/ 15)) +
  0.18 * improved_perlin_noise(sphere_fs_in * (vec3(5, 5, 5)/ 15))));
  kd = kd * (0.5 + noise);
  ka = ka * noise;
  color = blinn_phong(ka, kd, ks, p, n, v, l);

  /////////////////////////////////////////////////////////////////////////////
}
