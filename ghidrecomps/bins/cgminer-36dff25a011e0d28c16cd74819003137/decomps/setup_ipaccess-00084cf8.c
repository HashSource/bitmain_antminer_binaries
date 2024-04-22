
/* WARNING: Unknown calling convention */

void setup_ipaccess(void)

{
  char cVar1;
  bool bVar2;
  size_t sVar3;
  char *__dest;
  char *pcVar4;
  int iVar5;
  ushort **ppuVar6;
  int iVar7;
  bool bVar8;
  char tmp42 [2048];
  char original [64];
  char tmp [64];
  char *dot;
  char *slash;
  char *buf;
  char group;
  _Bool ipv6;
  int shift;
  int i;
  int mask;
  int ipcount;
  char *end;
  char *comma;
  char *ptr;
  
  sVar3 = strlen(opt_api_allow);
  __dest = (char *)_cgmalloc(sVar3 + 1,"api-btm.c","setup_ipaccess",0x1294);
  strcpy(__dest,opt_api_allow);
  ipcount = 1;
  ptr = __dest;
  while (*ptr != '\0') {
    pcVar4 = ptr + 1;
    cVar1 = *ptr;
    ptr = pcVar4;
    if (cVar1 == ',') {
      ipcount = ipcount + 1;
    }
  }
  ipaccess = (IPACCESS *)_cgcalloc(ipcount,0x24,"api-btm.c","setup_ipaccess",0x129f);
  ips = 0;
  ptr = __dest;
  do {
    while( true ) {
      if ((ptr == (char *)0x0) || (*ptr == '\0')) {
        free(__dest);
        return;
      }
      for (; (*ptr == ' ' || (*ptr == '\t')); ptr = ptr + 1) {
      }
      if (*ptr != ',') break;
      ptr = ptr + 1;
    }
    pcVar4 = strchr(ptr,0x2c);
    comma = pcVar4;
    if (pcVar4 != (char *)0x0) {
      comma = pcVar4 + 1;
      *pcVar4 = '\0';
    }
    strncpy(original,ptr,0x40);
    original[63] = '\0';
    iVar5 = toupper(0x52);
    group = (char)iVar5;
    ppuVar6 = __ctype_b_loc();
    if ((((*ppuVar6)[(byte)*ptr] & 0x400) != 0) && (ptr[1] == ':')) {
      iVar5 = toupper((uint)(byte)*ptr);
      iVar7 = toupper(0x57);
      if (iVar5 == iVar7) {
LAB_00084f40:
        iVar5 = toupper((uint)(byte)*ptr);
        group = (char)iVar5;
      }
      else {
        iVar5 = toupper((uint)(byte)*ptr);
        iVar7 = toupper(0x41);
        if (apigroups[iVar5 - iVar7].commands != (char *)0x0) goto LAB_00084f40;
      }
      ptr = ptr + 2;
    }
    ipaccess[ips].group = group;
    iVar5 = strcmp(ptr,"0/0");
    if (iVar5 == 0) {
      for (i = 0; i < 0x10; i = i + 1) {
        ipaccess[ips].ip.__in6_u.__u6_addr8[i] = '\0';
        ipaccess[ips].mask.__in6_u.__u6_addr8[i] = '\0';
      }
LAB_00085780:
      ips = ips + 1;
    }
    else {
      end = strchr(ptr,0x2f);
      if (end == (char *)0x0) {
        for (i = 0; i < 0x10; i = i + 1) {
          ipaccess[ips].mask.__in6_u.__u6_addr8[i] = 0xff;
        }
        sVar3 = strlen(ptr);
        end = ptr + sVar3;
      }
      if ((*ptr == '[') && (end[-1] == ']')) {
        *ptr = '\0';
        end[-1] = '\0';
        bVar2 = true;
        ptr = ptr + 1;
      }
      else {
        bVar2 = false;
      }
      if (*end == '\0') {
LAB_000853b8:
        for (i = 0; i < 0x10; i = i + 1) {
          ipaccess[ips].ip.__in6_u.__u6_addr8[i] = '\0';
        }
        if (bVar2) {
          iVar5 = inet_pton(10,ptr,ipaccess + ips);
          if (iVar5 == 1) {
LAB_00085698:
            for (i = 0; i < 0x10; i = i + 1) {
              ipaccess[ips].ip.__in6_u.__u6_addr8[i] =
                   ipaccess[ips].ip.__in6_u.__u6_addr8[i] & ipaccess[ips].mask.__in6_u.__u6_addr8[i]
              ;
            }
            goto LAB_00085780;
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            snprintf(tmp42,0x800,"API: ignored invalid IPv6 address \'%s\'",original);
            _applog(3,tmp42,false);
          }
        }
        else {
          pcVar4 = strchr(ptr,0x2e);
          if (pcVar4 == (char *)0x0) {
            snprintf(tmp,0x40,"::ffff:%s.0.0.0",ptr);
          }
          else {
            pcVar4 = strchr(pcVar4 + 1,0x2e);
            if (pcVar4 == (char *)0x0) {
              snprintf(tmp,0x40,"::ffff:%s.0.0",ptr);
            }
            else {
              pcVar4 = strchr(pcVar4 + 1,0x2e);
              if (pcVar4 == (char *)0x0) {
                snprintf(tmp,0x40,"::ffff:%s.0",ptr);
              }
              else {
                snprintf(tmp,0x40,"::ffff:%s",ptr);
              }
            }
          }
          iVar5 = inet_pton(10,tmp,ipaccess + ips);
          if (iVar5 == 1) goto LAB_00085698;
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            snprintf(tmp42,0x800,"API: ignored invalid IPv4 address \'%s\' (as %s)",original,tmp);
            _applog(3,tmp42,false);
          }
        }
      }
      else {
        *end = '\0';
        mask = atoi(end + 1);
        if (0 < mask) {
          if (bVar2) {
            iVar5 = 0;
          }
          else {
            iVar5 = 0x60;
          }
          mask = mask + iVar5;
          if (mask < 0x81) {
            for (i = 0; i < 0x10; i = i + 1) {
              ipaccess[ips].mask.__in6_u.__u6_addr8[i] = '\0';
            }
            i = 0;
            shift = 7;
            while (iVar5 = mask + -1, 0 < mask) {
              ipaccess[ips].mask.__in6_u.__u6_addr8[i] =
                   ipaccess[ips].mask.__in6_u.__u6_addr8[i] | (byte)(1 << (shift & 0xffU));
              bVar8 = shift == 0;
              shift = shift + -1;
              mask = iVar5;
              if (bVar8) {
                i = i + 1;
                shift = 7;
              }
            }
            goto LAB_000853b8;
          }
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"API: ignored address with invalid mask (%d) \'%s\'",mask,original);
          _applog(3,tmp42,false);
        }
      }
    }
    ptr = comma;
  } while( true );
}

