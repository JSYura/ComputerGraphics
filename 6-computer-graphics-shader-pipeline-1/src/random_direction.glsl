// Generate a pseudorandom unit 3D vector
// 
// Inputs:
//   seed  3D seed
// Returns psuedorandom, unit 3D vector drawn from uniform distribution over
// the unit sphere (assuming random2 is uniform over [0,1]²).
//
// expects: random2.glsl, PI.glsl
vec3 random_direction( vec3 seed)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code 
//  return vec3(1,0,0);
  vec2 random_pick = random2(seed);
  vec2 prod = M_PI * random_pick;
  float t = prod[0] / 2;
  float p = prod[1] / 2;
  vec3 compute = vec3(sin(t) * cos(p), sin(t) * sin(p), cos(t));
  return normalize(compute);
  /////////////////////////////////////////////////////////////////////////////
}
