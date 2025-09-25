
char * cmd_Certificate(int *param_1,char *param_2)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  
  if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
    iVar5 = param_1[4];
    if (iVar5 == 0) {
      return (char *)0x1;
    }
  }
  else {
    piVar2 = (int *)SSL_CTX_use_certificate_chain_file((SSL_CTX *)param_1[3],param_2);
    iVar5 = param_1[4];
    if (iVar5 == 0) {
      piVar4 = *(int **)(param_1[3] + 0xc0);
      goto LAB_000fdde4;
    }
  }
  piVar2 = (int *)SSL_use_certificate_chain_file(iVar5,param_2);
  piVar4 = *(int **)(param_1[4] + 0x404);
LAB_000fdde4:
  piVar1 = piVar4;
  if (piVar4 != (int *)0x0) {
    piVar1 = piVar2;
  }
  if ((piVar4 != (int *)0x0 && piVar2 != (int *)0x0) && -1 < (int)piVar1) {
    if (-1 < *param_1 << 0x19) {
      return (char *)0x1;
    }
    iVar5 = *piVar4 - (int)(piVar4 + 5) >> 2;
    CRYPTO_free((void *)param_1[iVar5 * 0xccccccd + 6]);
    pcVar3 = CRYPTO_strdup(param_2,"ssl/ssl_conf.c",0x1b7);
    param_1[iVar5 * 0xccccccd + 6] = (int)pcVar3;
    if (pcVar3 != (char *)0x0) {
      pcVar3 = (char *)0x1;
    }
    return pcVar3;
  }
  return (char *)(uint)(0 < (int)piVar2);
}

