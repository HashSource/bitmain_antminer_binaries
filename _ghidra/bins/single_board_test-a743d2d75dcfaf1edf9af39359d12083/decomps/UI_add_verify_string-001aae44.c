
int UI_add_verify_string
              (UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize,char *test_buf
              )

{
  int iVar1;
  
  iVar1 = general_allocate_string(ui,prompt,0,2,flags,result_buf,minsize,maxsize,test_buf);
  return iVar1;
}

