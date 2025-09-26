
size_t EC_GROUP_get_seed_len(EC_GROUP *param_1)

{
  return *(size_t *)(param_1 + 0x40);
}

