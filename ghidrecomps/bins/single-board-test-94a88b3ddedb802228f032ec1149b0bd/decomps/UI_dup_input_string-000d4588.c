
int UI_dup_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  char *pcVar1;
  int iVar2;
  
  if (prompt == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = BUF_strdup(prompt);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x28,0x67,0x41,DAT_000d45dc,0xf9);
      return 0;
    }
  }
  iVar2 = general_allocate_string(ui,pcVar1,1,1,flags,result_buf,minsize,maxsize,0);
  return iVar2;
}

