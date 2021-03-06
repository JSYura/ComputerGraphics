// Set the pixel color to an interesting procedural color generated by mixing
// and filtering Perlin noise of different frequencies.
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

// expects: blinn_phong, perlin_noise
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

  n = normalize(normal_fs_in);
  v = ((view * view_pos_fs_in).xyz);
  l = ((view * mat_rot * vec4(1, 1, 0, 0))).xyz;
  if (is_moon) {
      p = 250;
      ka = vec3(0.04);
      kd = vec3(0.52);
      ks = vec3(0.85);
     } else {
      p = 1500;
      ka = vec3(0.02, 0.02, 0.16);
      kd = vec3(0.25, 0.25, 0.8);
      ks = vec3(0.98);
     }

  float noise = abs(
  M_PI * (0.7 * perlin_noise(sphere_fs_in * vec3(4, 10, 2) * (vec3(5, 5, 5)/ 15)) +
  0.18 * perlin_noise(sphere_fs_in * (vec3(5, 5, 5)/ 15))));
  kd = kd * (0.5 + noise);
  ka = ka * noise;
  color = blinn_phong(ka, kd, ks, p, n, v, l);

  /////////////////////////////////////////////////////////////////////////////
}
