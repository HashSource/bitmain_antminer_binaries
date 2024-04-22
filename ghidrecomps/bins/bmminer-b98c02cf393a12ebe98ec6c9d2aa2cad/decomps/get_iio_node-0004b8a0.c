
float get_iio_node(int param_1,int param_2)

{
  int __fd;
  char *pcVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  char local_35;
  char acStack_34 [5];
  undefined local_2f;
  
  local_35 = '\0';
  sprintf(&gNodeName,"%s/%s","/sys/bus/iio/devices/iio:device0",
          *(int *)(param_1 + param_2 * 4) + 0xb);
  __fd = open(&gNodeName,2);
  pcVar1 = strstr(&gNodeName,"temp");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strstr(&gNodeName,"voltage");
    fVar5 = DAT_0004ba48;
    if ((pcVar1 != (char *)0x0) &&
       (pcVar1 = strstr(&gNodeName,"raw"), fVar5 = DAT_0004ba48, pcVar1 != (char *)0x0)) {
      iVar4 = 0;
      pcVar1 = acStack_34;
      do {
        iVar3 = iVar4 + 1;
        lseek(__fd,iVar4,0);
        read(__fd,&local_35,1);
        *pcVar1 = local_35;
        iVar4 = iVar3;
        pcVar1 = pcVar1 + 1;
      } while (iVar3 != 5);
      local_2f = 0;
      lVar2 = strtol(acStack_34,(char **)0x0,10);
      fVar5 = (float)((double)(longlong)lVar2 * 3.0 * DAT_0004ba40 * DAT_0004ba30);
    }
  }
  else {
    pcVar1 = strstr(&gNodeName,"raw");
    fVar5 = DAT_0004ba48;
    if (pcVar1 != (char *)0x0) {
      iVar4 = 0;
      pcVar1 = acStack_34;
      do {
        iVar3 = iVar4 + 1;
        lseek(__fd,iVar4,0);
        read(__fd,&local_35,1);
        *pcVar1 = local_35;
        iVar4 = iVar3;
        pcVar1 = pcVar1 + 1;
      } while (iVar3 != 5);
      local_2f = 0;
      lVar2 = strtol(acStack_34,(char **)0x0,10);
      fVar5 = (float)((double)(longlong)lVar2 * DAT_0004ba28 * DAT_0004ba30 - DAT_0004ba38);
    }
  }
  close(__fd);
  return fVar5;
}

