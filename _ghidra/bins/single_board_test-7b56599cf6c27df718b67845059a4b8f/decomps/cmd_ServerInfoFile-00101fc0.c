
bool cmd_ServerInfoFile(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    return true;
  }
  iVar1 = SSL_CTX_use_serverinfo_file();
  return 0 < iVar1;
}

