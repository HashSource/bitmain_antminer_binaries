
int UI_add_input_string(UI *ui,char *prompt,int flags,char *result_buf,int minsize,int maxsize)

{
  int iVar1;
  
  iVar1 = general_allocate_string(ui,prompt,0,1,flags,result_buf,minsize,maxsize,0);
  return iVar1;
}

