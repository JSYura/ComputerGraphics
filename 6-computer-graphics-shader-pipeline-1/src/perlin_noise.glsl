// Given a 3d position as a seed, compute a smooth procedural noise
// value: "Perlin Noise", also known as "Gradient noise".
//
// Inputs:
//   st  3D seed
// Returns a smooth value between (-1,1)
//
// expects: random_direction, smooth_step
float perlin_noise( vec3 st) 
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
//  return 0;
  float x_floor = floor(st.x);
  float y_floor = floor(st.y);
  float z_floor = floor(st.z);
  float x_plus = x_floor + 1;
  float y_plus = y_floor + 1;
  float z_plus = z_floor + 1;

  vec3 v1, v2, v3, v4, v5, v6, v7, v8;
  vec3 g1, g2, g3, g4, g5, g6, g7, g8;
  v1 = vec3(x_floor, y_floor, z_floor);
  v2 = vec3(x_floor, y_floor, z_plus);
  v3 = vec3(x_floor, y_plus, z_floor);
  v4 = vec3(x_floor, y_plus, z_plus);
  v5 = vec3(x_plus, y_floor, z_floor);
  v6 = vec3(x_plus, y_floor, z_plus);
  v7 = vec3(x_plus, y_plus, z_floor);
  v8 = vec3(x_plus, y_plus, z_plus);

  g1 = random_direction(v1);
  g2 = random_direction(v2);
  g3 = random_direction(v3);
  g4 = random_direction(v4);
  g5 = random_direction(v5);
  g6 = random_direction(v6);
  g7 = random_direction(v7);
  g8 = random_direction(v8);

  vec3 u1, u2, u3, u4, u5, u6, u7, u8;
  // dot product
  float p1, p2, p3, p4, p5, p6, p7, p8;

  u1 = -v1 + st;
  u2 = -v2 + st;
  u3 = -v3 + st;
  u4 = -v4 + st;
  u5 = -v5 + st;
  u6 = -v6 + st;
  u7 = -v7 + st;
  u8 = -v8 + st;

  p1 = dot(g1, u1);
  p2 = dot(g2, u2);
  p3 = dot(g3, u3);
  p4 = dot(g4, u4);
  p5 = dot(g5, u5);
  p6 = dot(g6, u6);
  p7 = dot(g7, u7);
  p8 = dot(g8, u8);

  vec3 smooth_st = smooth_step(st - v1);
  float x_15, x_26, x_37, x_48, y_1537, y_2648;
  x_15 = p1 + (smooth_st.x * (p5 - p1));
  x_26 = p2 + (smooth_st.x * (p6 - p2));
  x_37 = p3 + (smooth_st.x * (p7 - p3));
  x_48 = p4 + (smooth_st.x * (p8 - p4));
  y_1537 = x_15 + (smooth_st.y * (x_37 - x_15));
  y_2648 = x_26 + (smooth_st.y * (x_48 - x_26));

  return 3 * (y_1537 + (smooth_st.z * (y_2648 - y_1537))) / sqrt(2);
  /////////////////////////////////////////////////////////////////////////////
}

