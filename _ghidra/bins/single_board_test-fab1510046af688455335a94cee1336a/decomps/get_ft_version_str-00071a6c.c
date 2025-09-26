
void get_ft_version_str(ft_bin_t *ft_bin,char *ft_str)

{
  undefined4 uVar1;
  char *ft_str_local;
  ft_bin_t *ft_bin_local;
  
  if ((ft_bin != (ft_bin_t *)0x0) && (ft_str != (char *)0x0)) {
    if (((uint)*ft_bin & 1) == 0) {
      uVar1 = 0x45;
    }
    else {
      uVar1 = 0x46;
    }
    snprintf(ft_str,10,"%c%dV%02dB%dC%d",uVar1,((uint)*(byte *)ft_bin << 0x1c) >> 0x1d,
             ((uint)*(ushort *)ft_bin << 0x16) >> 0x1a,
             ((uint)*(byte *)((int)ft_bin + 1) << 0x1b) >> 0x1d,
             ((uint)*(byte *)((int)ft_bin + 1) << 0x19) >> 0x1e);
  }
  return;
}

