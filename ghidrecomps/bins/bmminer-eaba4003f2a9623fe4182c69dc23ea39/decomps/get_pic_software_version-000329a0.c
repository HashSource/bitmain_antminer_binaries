
void get_pic_software_version(uchar chain,uchar *version)

{
  uchar uVar1;
  uchar *version_local;
  uchar chain_local;
  int i;
  
  send_pic_command(chain);
  write_pic_iic(false,false,'\0',chain,'\x17');
  for (i = 0; i < 1; i = i + 1) {
    uVar1 = write_pic_iic(true,false,'\0',chain,'\0');
    version[i] = uVar1;
  }
  return;
}

