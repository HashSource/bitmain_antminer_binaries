
char http_negotiate(int param_1,int param_2,int param_3)

{
  char cVar1;
  char cVar2;
  size_t __n;
  ssize_t sVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  undefined4 uVar7;
  char *pcVar8;
  bool bVar9;
  char local_c20 [1024];
  char local_820 [2048];
  
  uVar5 = *(undefined4 *)(param_1 + 600);
  uVar7 = *(undefined4 *)(param_1 + 0x248);
  if (param_3 == 0) {
    snprintf(local_c20,0x400,"CONNECT %s:%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n",uVar5,uVar7,uVar5,uVar7
            );
  }
  else {
    snprintf(local_c20,0x400,"CONNECT %s:%s HTTP/1.0\r\n\r\n",uVar5,uVar7);
  }
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(local_820,0x800,"Sending proxy %s:%s - %s",*(undefined4 *)(param_1 + 0x25c),
             *(undefined4 *)(param_1 + 0x260),local_c20);
    _applog(7,local_820,0);
  }
  __n = strlen(local_c20);
  send(param_2,local_c20,__n,0);
  sVar3 = recv(param_2,local_c20,0xc,0);
  if (sVar3 < 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(local_820,0x800,"Couldn\'t read from proxy %s:%s after sending CONNECT",
               *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
      _applog(4,local_820,0);
      return '\0';
    }
  }
  else {
    local_c20[sVar3] = '\0';
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_820,0x800,"Received from proxy %s:%s - %s",*(undefined4 *)(param_1 + 0x25c),
               *(undefined4 *)(param_1 + 0x260),local_c20);
      _applog(7,local_820,0);
    }
    iVar4 = strcmp(local_c20,"HTTP/1.1 200");
    if ((iVar4 == 0) || (iVar4 = strcmp(local_c20,"HTTP/1.0 200"), iVar4 == 0)) {
      iVar4 = 0;
      pcVar8 = local_c20;
      do {
        sVar3 = recv(param_2,local_820,1,0);
        if (sVar3 == -1) {
          local_c20[iVar4] = -1;
          goto LAB_0004573c;
        }
        iVar4 = iVar4 + 1;
        bVar9 = local_820[0] == -1;
        *pcVar8 = local_820[0];
        if (bVar9) goto LAB_0004573c;
        pcVar8 = pcVar8 + 1;
      } while (iVar4 != 4);
      iVar4 = strncmp(local_c20,"\r\n\r\n",4);
      cVar1 = opt_debug;
      cVar2 = local_c20[0];
      local_c20[0] = local_c20[1];
      local_c20[1] = local_c20[2];
      local_c20[2] = local_c20[3];
      while( true ) {
        opt_debug = cVar1;
        local_c20[3] = local_c20[2];
        if (iVar4 == 0) {
          if (cVar1 == '\0') {
            cVar6 = '\x01';
          }
          else if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                  (cVar6 = cVar1, 6 < opt_log_level)) {
            cVar6 = local_c20[0];
            local_c20[0] = cVar2;
            local_c20[2] = local_c20[1];
            local_c20[1] = cVar6;
            snprintf(local_820,0x800,"Success negotiating with %s:%s HTTP proxy",
                     *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
            _applog(7,local_820,0);
            return cVar1;
          }
          return cVar6;
        }
        sVar3 = recv(param_2,local_820,1,0);
        if (sVar3 == -1) break;
        local_c20[3] = local_820[0];
        if (local_820[0] == -1) goto LAB_0004573c;
        iVar4 = strncmp(local_c20,"\r\n\r\n",4);
        cVar1 = opt_debug;
        cVar2 = local_c20[0];
        local_c20[0] = local_c20[1];
        local_c20[1] = local_c20[2];
        local_c20[2] = local_c20[3];
      }
      local_c20[3] = -1;
LAB_0004573c:
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(local_820,0x800,"Couldn\'t read HTTP byte from proxy %s:%s",
                 *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
        _applog(4,local_820,0);
        return '\0';
      }
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(local_820,0x800,"HTTP Error from proxy %s:%s - %s",*(undefined4 *)(param_1 + 0x25c),
               *(undefined4 *)(param_1 + 0x260),local_c20);
      _applog(4,local_820);
      return '\0';
    }
  }
  return '\0';
}

