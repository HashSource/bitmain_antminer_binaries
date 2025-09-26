
undefined4 tls_process_cert_status(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = tls_process_cert_status_body();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

