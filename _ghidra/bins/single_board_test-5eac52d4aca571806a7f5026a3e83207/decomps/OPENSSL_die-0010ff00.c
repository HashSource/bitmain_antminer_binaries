
void OPENSSL_die(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  OPENSSL_showfatal("%s:%d: OpenSSL internal error: %s\n",param_2,param_3,param_1,param_4);
                    /* WARNING: Subroutine does not return */
  abort();
}

