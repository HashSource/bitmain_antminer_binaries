
void encode_multi_ft_version(ft_bin_list_t *f)

{
  int iVar1;
  ft_bin_list_t *f_local;
  int i;
  
  for (i = 0; i < 2; i = i + 1) {
    iVar1 = get_ft_head_encode(f->chip_ftversion[i][0]);
    *(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) =
         (uint)f->chip_col[i] +
         (uint)f->chip_bin[i] * 10 +
         iVar1 * 10000000 + ((byte)f->chip_ftversion[i][1] - 0x30) * 1000000 +
         ((byte)f->chip_ftversion[i][3] - 0x30) * 100000 +
         ((byte)f->chip_ftversion[i][4] - 0x30) * 10000 +
         ((byte)f->chip_ftversion[i][6] - 0x30) * 1000 +
         ((byte)f->chip_ftversion[i][8] - 0x30) * 100;
  }
  (f->ft_value).u.head = 0xf0;
  (f->ft_value).u.tail = '\0';
  return;
}

