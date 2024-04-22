
int dir_ctrl(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  if (param_2 != 2) {
    return 0;
  }
  if (param_4 != 3) {
    if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
      iVar1 = add_cert_dir_part_0(uVar3,param_3,param_4);
      return iVar1;
    }
    ERR_put_error(0xb,100,0x71,DAT_000c5c74,0xcc);
    return 0;
  }
  pcVar2 = X509_get_default_cert_dir_env();
  pcVar2 = getenv(pcVar2);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = X509_get_default_cert_dir();
    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
      ERR_put_error(0xb,100,0x71,DAT_000c5c74,0xcc);
      iVar1 = 0;
      goto LAB_000c5c3e;
    }
  }
  else if (*pcVar2 == '\0') {
    ERR_put_error(0xb,100,0x71,DAT_000c5c74,0xcc);
    iVar1 = 0;
    goto LAB_000c5c3e;
  }
  iVar1 = add_cert_dir_part_0(uVar3,pcVar2,1);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_000c5c3e:
  ERR_put_error(0xb,0x66,0x67,DAT_000c5c74,0x8a);
  return iVar1;
}

