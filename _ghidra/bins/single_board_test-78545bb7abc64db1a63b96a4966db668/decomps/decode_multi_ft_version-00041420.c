
void decode_multi_ft_version(ft_bin_list_t *f)

{
  char cVar1;
  uint uVar2;
  ft_bin_list_t *f_local;
  int i;
  
  for (i = 0; i < 2; i = i + 1) {
    uVar2 = *(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4);
    f->chip_col[i] = (char)uVar2 + (char)(uVar2 / 10) * -10;
    uVar2 = *(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 10;
    f->chip_bin[i] = (char)uVar2 + (char)(uVar2 / 10) * -10;
    uVar2 = *(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 10000000;
    cVar1 = decode_ft_head((char)uVar2 + (char)(uVar2 / 10) * -10);
    sprintf(f->chip_ftversion[i],"%c%dV%d%dB%dC%d",(int)cVar1,
            (*(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 1000000) % 10,
            (*(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 100000) % 10,
            (*(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 10000) % 10,
            (*(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 1000) % 10,
            (*(uint *)((int)(f->chip_ftversion + -1) + 7 + i * 4) / 100) % 10);
  }
  return;
}

