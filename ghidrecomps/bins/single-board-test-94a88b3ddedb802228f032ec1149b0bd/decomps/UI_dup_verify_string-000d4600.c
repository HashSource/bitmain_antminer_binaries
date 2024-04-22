
int UI_dup_verify_string
              (UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize,char *test_buf
              )

{
  int iVar1;
  
  if ((prompt == (char *)0x0) || (prompt = BUF_strdup(prompt), prompt != (char *)0x0)) {
    iVar1 = general_allocate_string(ui,prompt,1,2,flags,result_buf,minsize,maxsize,test_buf);
  }
  else {
    ERR_put_error(0x28,0x6a,0x41,DAT_000d464c,0x115);
    iVar1 = -1;
  }
  return iVar1;
}

