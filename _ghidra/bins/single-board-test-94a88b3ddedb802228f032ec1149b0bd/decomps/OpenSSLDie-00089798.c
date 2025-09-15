
void OpenSSLDie(char *file,int line,char *assertion)

{
  OPENSSL_showfatal("%s(%d): OpenSSL internal error, assertion failed: %s\n",file,line,assertion);
                    /* WARNING: Subroutine does not return */
  abort();
}

