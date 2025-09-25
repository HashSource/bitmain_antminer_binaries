
uint ecx_pub_print(BIO *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 0x18);
  pcVar1 = OBJ_nid2ln(**(int **)(param_2 + 0xc));
  if (iVar5 == 0) {
    iVar5 = BIO_printf(param_1,"%*s<INVALID PUBLIC KEY>\n",param_3,"");
    return (uint)(0 < iVar5);
  }
  iVar2 = BIO_printf(param_1,"%*s%s Public-Key:\n",param_3,"",pcVar1);
  if ((0 < iVar2) && (iVar2 = BIO_printf(param_1,"%*spub:\n",param_3,"",pcVar1), 0 < iVar2)) {
    iVar2 = **(int **)(param_2 + 0xc);
    if (iVar2 == 0x40a || iVar2 == 0x43f) {
      uVar4 = 0x20;
    }
    else if (iVar2 == 0x40b) {
      uVar4 = 0x38;
    }
    else {
      uVar4 = 0x39;
    }
    uVar3 = ASN1_buf_print(param_1,iVar5,uVar4,param_3 + 4);
    if (uVar3 != 0) {
      uVar3 = 1;
    }
    return uVar3;
  }
  return 0;
}

