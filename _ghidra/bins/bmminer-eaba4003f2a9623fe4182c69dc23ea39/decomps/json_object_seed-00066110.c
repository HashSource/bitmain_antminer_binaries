
void json_object_seed(size_t seed)

{
  size_t seed_local;
  uint32_t new_seed;
  
  if (hashtable_seed == 0) {
    new_seed = seed;
    if (seed == 0) {
      new_seed = generate_seed();
    }
    hashtable_seed = new_seed;
  }
  return;
}

