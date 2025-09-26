
void cmd_ClientCAFile(int param_1,char *param_2)

{
  stack_st_X509_NAME *stackCAs;
  
  if (*(stack_st_X509_NAME **)(param_1 + 0x54) != (stack_st_X509_NAME *)0x0) {
    SSL_add_file_cert_subjects_to_stack(*(stack_st_X509_NAME **)(param_1 + 0x54),param_2);
    return;
  }
  stackCAs = (stack_st_X509_NAME *)OPENSSL_sk_new_null();
  *(stack_st_X509_NAME **)(param_1 + 0x54) = stackCAs;
  if (stackCAs == (stack_st_X509_NAME *)0x0) {
    return;
  }
  SSL_add_file_cert_subjects_to_stack(stackCAs,param_2);
  return;
}

