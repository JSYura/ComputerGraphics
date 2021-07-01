// Add (hard code) an orbiting (point or directional) light to the scene. Light
// the scene using the Blinn-Phong Lighting Model.
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
// expects: PI, blinn_phong
void main()
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
//   color = vec3(1,1,1);
   vec3 ka, kd, ks, v, l;
   float p;
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
   mat4 mat_rot = mat4(
      cos(animation_seconds * M_PI / 2.0), 0, sin(animation_seconds * M_PI / 2.0), 0,
      0, 1.0, 0, 0,
      -sin(animation_seconds * M_PI / 2.0), 0, cos(animation_seconds * M_PI / 2.0), 0,
      0, 0, 0, 1.0);
   l = ((view * mat_rot * vec4(1, 1, 0, 0))).xyz;
   v = ((view * view_pos_fs_in).xyz);
   color = blinn_phong(ka, kd, ks, p, normalize(normal_fs_in), v, l);
  /////////////////////////////////////////////////////////////////////////////
}
