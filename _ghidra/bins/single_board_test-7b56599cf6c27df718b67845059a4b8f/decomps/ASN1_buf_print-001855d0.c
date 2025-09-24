
bool ASN1_buf_print(BIO *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (param_3 != 0) {
    pbVar5 = (byte *)(param_2 + -1);
    uVar4 = 0;
    iVar2 = param_4;
    do {
      if ((uVar4 == (uVar4 / 0xf) * 0xf) &&
         (((uVar4 != 0 && (iVar1 = BIO_puts(param_1,"\n"), iVar1 < 1)) ||
          (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 == 0)))) {
        return false;
      }
      pbVar5 = pbVar5 + 1;
      pcVar3 = ":";
      if (param_3 - 1 == uVar4) {
        pcVar3 = "";
      }
      uVar4 = uVar4 + 1;
      iVar1 = BIO_printf(param_1,"%02x%s",(uint)*pbVar5,pcVar3,iVar2);
      if (iVar1 < 1) {
        return false;
      }
    } while (param_3 != uVar4);
  }
  iVar2 = BIO_write(param_1,"\n",1);
  return 0 < iVar2;
}

