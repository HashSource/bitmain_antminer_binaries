
undefined4 X509_check_ip(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = do_x509_check_constprop_4();
    return uVar1;
  }
  return 0xfffffffe;
}

