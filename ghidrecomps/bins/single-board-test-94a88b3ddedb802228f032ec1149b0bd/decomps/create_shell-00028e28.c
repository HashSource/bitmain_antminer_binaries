
undefined4 create_shell(undefined4 param_1)

{
  size_t sVar1;
  undefined4 local_40c;
  undefined4 uStack_408;
  undefined2 local_404;
  undefined local_402;
  FILE *local_c;
  
  local_c = fopen("/etc/config/run.sh","wb");
  local_40c = DAT_00130820;
  uStack_408 = DAT_00130824;
  local_404 = (undefined2)DAT_00130828;
  local_402 = (undefined)((uint)DAT_00130828 >> 0x10);
  sVar1 = strlen((char *)&local_40c);
  fwrite(&local_40c,1,sVar1,local_c);
  sprintf((char *)&local_40c,"%s\n",param_1);
  sVar1 = strlen((char *)&local_40c);
  fwrite(&local_40c,1,sVar1,local_c);
  fclose(local_c);
  system("chmod +x /etc/config/run.sh");
  return 0;
}

