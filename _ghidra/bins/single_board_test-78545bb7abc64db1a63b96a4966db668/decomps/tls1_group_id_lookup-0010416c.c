
undefined4 * tls1_group_id_lookup(int param_1)

{
  if ((param_1 - 1U & 0xffff) < 0x1e) {
    return &nid_list + (param_1 - 1U) * 3;
  }
  return (undefined4 *)0x0;
}

