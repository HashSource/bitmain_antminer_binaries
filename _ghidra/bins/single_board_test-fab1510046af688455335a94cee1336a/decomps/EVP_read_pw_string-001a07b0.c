
int EVP_read_pw_string(char *buf,int length,char *prompt,int verify)

{
  int iVar1;
  
  iVar1 = EVP_read_pw_string_min(buf,0,length,prompt,verify);
  return iVar1;
}

