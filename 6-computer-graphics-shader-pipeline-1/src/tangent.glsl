// Input:
//   N  3D unit normal vector
// Outputs:
//   T  3D unit tangent vector
//   B  3D unit bitangent vector
void tangent(in vec3 N, out vec3 T, out vec3 B)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  vec3 n1, n2, n3;
  n1 = vec3(1,0,0);
  n2 = vec3(0,1,0);
  n3 = vec3(0,0,1);
  T = normalize(cross(N, n2));
  if (length(n1) <= length(n3)){
    T = normalize(cross(N, n3));
  }
  B = normalize(cross(N, T));
  /////////////////////////////////////////////////////////////////////////////
}
