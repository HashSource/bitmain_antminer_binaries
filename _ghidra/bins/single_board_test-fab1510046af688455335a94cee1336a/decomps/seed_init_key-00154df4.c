
undefined4 seed_init_key(int param_1,uchar *param_2)

{
  SEED_set_key(param_2,*(SEED_KEY_SCHEDULE **)(param_1 + 0x60));
  return 1;
}

