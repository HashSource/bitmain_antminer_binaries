
void SSL_add1_host(int param_1,undefined4 param_2)

{
  X509_VERIFY_PARAM_add1_host(*(undefined4 *)(param_1 + 0x90),param_2,0);
  return;
}

