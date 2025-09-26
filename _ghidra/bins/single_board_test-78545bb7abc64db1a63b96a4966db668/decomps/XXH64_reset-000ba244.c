
XXH_errorcode XXH64_reset(XXH64_state_t *statePtr,ulonglong seed)

{
  ulonglong seed_local;
  XXH64_state_t *statePtr_local;
  XXH64_state_t state;
  
  memset(&state,0,0x58);
  seed_local._0_4_ = (uint)seed;
  seed_local._4_4_ = (int)(seed >> 0x20);
  state.v1._0_4_ = (uint)seed_local + 0xadc0b5d6;
  state.v1._4_4_ =
       seed_local._4_4_ + (uint)(0x7a143578 < (uint)seed_local) +
       (0xd82b14b0 < (uint)seed_local + 0x85ebca87) + 0x60ea27ee;
  state.v2 = seed + 0xc2b2ae3d27d4eb4f;
  state.v4._0_4_ = (uint)seed_local + 0x7a143579;
  state.v4._4_4_ = (seed_local._4_4_ + 0x61c8864f) - (uint)((uint)seed_local < 0x85ebca87);
  state.v3 = seed;
  memcpy(statePtr,&state,0x50);
  return XXH_OK;
}

