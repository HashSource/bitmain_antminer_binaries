
int transform_txt_to_bin(char *input_file,char *output_file)

{
  FILE *__stream;
  FILE *__s;
  long lVar1;
  uint32_t uVar2;
  char *pcVar3;
  int iVar4;
  pattern_struct_in_file *dst;
  char *output_file_local;
  char *input_file_local;
  pattern_struct_in_file super [128];
  char *endptr;
  char str [512];
  pattern_struct_in_file *new_work;
  FILE *output_fp;
  FILE *input_fp;
  int idx;
  int i_1;
  int i;
  int64_t line_num;
  char *temp;
  
  memset(str,0,0x200);
  memset(super,0,0x1800);
  __stream = fopen(input_file,"r");
  if (__stream == (FILE *)0x0) {
    printf("Fail to open pattern file %s.\n",input_file);
    iVar4 = -1;
  }
  else {
    __s = fopen(output_file,"w");
    if (__s == (FILE *)0x0) {
      printf("Fail to open pattern file %s.\n",output_file);
      iVar4 = -1;
    }
    else {
      while ((pcVar3 = fgets(str,0x1ff,__stream), pcVar3 != (char *)0x0 &&
             (iVar4 = feof(__stream), iVar4 == 0))) {
        pcVar3 = strstr(str,"coreid");
        if (pcVar3 == (char *)0x0) {
          printf("Fail to read line[%lld] nonce\n");
          return -1;
        }
        for (temp = pcVar3 + 6; *temp == ' '; temp = temp + 1) {
        }
        lVar1 = strtol(temp,&endptr,10);
        printf("read coreid :%d ",lVar1);
        if ((lVar1 < 0) || (0x80 < lVar1)) {
          puts("prase coreid failed");
          return -1;
        }
        dst = super + lVar1;
        uVar2 = htonl(dst->nonce);
        dst->nonce = uVar2;
        pcVar3 = strstr(str,"nonce");
        if (pcVar3 == (char *)0x0) {
          printf("Fail to read line[%lld] nonce\n");
          return -1;
        }
        for (temp = pcVar3 + 5; *temp == ' '; temp = temp + 1) {
        }
        s2hex((uchar *)dst,temp,8);
        uVar2 = htonl(dst->nonce);
        dst->nonce = uVar2;
        printf("load nonce:0x%08x \n",dst->nonce);
        pcVar3 = strstr(str,"midstate");
        if (pcVar3 == (char *)0x0) {
          printf("Fail to read line[%lld] midstate\n");
          return -1;
        }
        for (temp = pcVar3 + 8; *temp == ' '; temp = temp + 1) {
        }
        s2hex(super[lVar1].midstate,temp,0x40);
        pcVar3 = strstr(str,"data");
        if (pcVar3 == (char *)0x0) {
          printf("Fail to read line[%lld] data\n");
          return -1;
        }
        for (temp = pcVar3 + 4; *temp == ' '; temp = temp + 1) {
        }
        s2hex(super[lVar1].data,temp,0x18);
      }
      for (i = 0; i < 0x80; i = i + 1) {
        if (super[i].nonce == 0) {
          printf("Fail to read coreid:%d nonce\n",i);
          return -1;
        }
      }
      for (i_1 = 0; i_1 < 0x80; i_1 = i_1 + 1) {
        fwrite(super + i_1,1,0x30,__s);
      }
      puts("gen /mnt/card/BM1370-pattern/pattern_1midstate_super.bin success!");
      fclose(__stream);
      fclose(__s);
      iVar4 = 0;
    }
  }
  return iVar4;
}

