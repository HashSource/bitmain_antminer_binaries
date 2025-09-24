
undefined4 X509_check_ip_asc(undefined4 param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uchar auStack_28 [20];
  
  if (param_2 != (char *)0x0) {
    iVar1 = a2i_ipadd(auStack_28,param_2);
    if (iVar1 == 0) {
      uVar2 = 0xfffffffe;
    }
    else {
      uVar2 = do_x509_check(param_1,auStack_28,iVar1,param_3,7,0);
    }
    return uVar2;
  }
  return 0xfffffffe;
}

