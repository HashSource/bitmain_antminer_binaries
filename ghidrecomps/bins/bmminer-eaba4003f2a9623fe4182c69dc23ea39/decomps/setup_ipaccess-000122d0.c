
/* WARNING: Unknown calling convention */

void setup_ipaccess(void)

{
  bool bVar1;
  size_t sVar2;
  char *__dest;
  int iVar3;
  ushort **ppuVar4;
  int iVar5;
  char *pcVar6;
  char cVar7;
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
  
  sVar2 = strlen(opt_api_allow);
  __dest = (char *)_cgmalloc(sVar2 + 1,"api-btm.c","setup_ipaccess",0x1286);
  strcpy(__dest,opt_api_allow);
  ipcount = 1;
  ptr = __dest;
  while (*ptr != '\0') {
    cVar7 = *ptr;
    ptr = ptr + 1;
    if (cVar7 == ',') {
      ipcount = ipcount + 1;
    }
  }
  ipaccess = (IPACCESS *)_cgcalloc(ipcount,0x24,"api-btm.c","setup_ipaccess",0x1291);
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
    comma = strchr(ptr,0x2c);
    if (comma != (char *)0x0) {
      *comma = '\0';
      comma = comma + 1;
    }
    strncpy(original,ptr,0x40);
    original[63] = '\0';
    iVar3 = toupper(0x52);
    group = (char)iVar3;
    ppuVar4 = __ctype_b_loc();
    if ((((*ppuVar4)[(byte)*ptr] & 0x400) != 0) && (ptr[1] == ':')) {
      iVar3 = toupper((uint)(byte)*ptr);
      iVar5 = toupper(0x57);
      if (iVar3 == iVar5) {
LAB_00012494:
        iVar3 = toupper((uint)(byte)*ptr);
        group = (char)iVar3;
      }
      else {
        iVar3 = toupper((uint)(byte)*ptr);
        iVar5 = toupper(0x41);
        if (apigroups[iVar3 - iVar5].commands != (char *)0x0) goto LAB_00012494;
      }
      ptr = ptr + 2;
    }
    ipaccess[ips].group = group;
    iVar3 = strcmp(ptr,"0/0");
    if (iVar3 == 0) {
      for (i = 0; i < 0x10; i = i + 1) {
        ipaccess[ips].ip.__in6_u.__u6_addr8[i] = '\0';
        ipaccess[ips].mask.__in6_u.__u6_addr8[i] = '\0';
      }
LAB_00012a7a:
      ips = ips + 1;
    }
    else {
      end = strchr(ptr,0x2f);
      if (end == (char *)0x0) {
        for (i = 0; i < 0x10; i = i + 1) {
          ipaccess[ips].mask.__in6_u.__u6_addr8[i] = 0xff;
        }
        sVar2 = strlen(ptr);
        end = ptr + sVar2;
      }
      if ((*ptr == '[') && (end[-1] == ']')) {
        *ptr = '\0';
        ptr = ptr + 1;
        end[-1] = '\0';
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (*end == '\0') {
LAB_000127d6:
        for (i = 0; i < 0x10; i = i + 1) {
          ipaccess[ips].ip.__in6_u.__u6_addr8[i] = '\0';
        }
        if (bVar1) {
          iVar3 = inet_pton(10,ptr,ipaccess + ips);
          if (iVar3 == 1) {
LAB_000129e2:
            for (i = 0; i < 0x10; i = i + 1) {
              ipaccess[ips].ip.__in6_u.__u6_addr8[i] =
                   ipaccess[ips].mask.__in6_u.__u6_addr8[i] & ipaccess[ips].ip.__in6_u.__u6_addr8[i]
              ;
            }
            goto LAB_00012a7a;
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            snprintf(tmp42,0x800,"API: ignored invalid IPv6 address \'%s\'",original);
            _applog(3,tmp42,false);
          }
        }
        else {
          pcVar6 = strchr(ptr,0x2e);
          if (pcVar6 == (char *)0x0) {
            snprintf(tmp,0x40,"::ffff:%s.0.0.0",ptr);
          }
          else {
            pcVar6 = strchr(pcVar6 + 1,0x2e);
            if (pcVar6 == (char *)0x0) {
              snprintf(tmp,0x40,"::ffff:%s.0.0",ptr);
            }
            else {
              pcVar6 = strchr(pcVar6 + 1,0x2e);
              if (pcVar6 == (char *)0x0) {
                snprintf(tmp,0x40,"::ffff:%s.0",ptr);
              }
              else {
                snprintf(tmp,0x40,"::ffff:%s",ptr);
              }
            }
          }
          iVar3 = inet_pton(10,tmp,ipaccess + ips);
          if (iVar3 == 1) goto LAB_000129e2;
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
          if (bVar1) {
            iVar3 = 0;
          }
          else {
            iVar3 = 0x60;
          }
          mask = mask + iVar3;
          if (mask < 0x81) {
            for (i = 0; i < 0x10; i = i + 1) {
              ipaccess[ips].mask.__in6_u.__u6_addr8[i] = '\0';
            }
            i = 0;
            shift = 7;
            while( true ) {
              iVar3 = mask;
              if (mask < 1) {
                iVar3 = 0;
              }
              cVar7 = (char)iVar3;
              if (0 < mask) {
                cVar7 = '\x01';
              }
              mask = mask + -1;
              if (cVar7 == '\0') break;
              ipaccess[ips].mask.__in6_u.__u6_addr8[i] =
                   (byte)(1 << (shift & 0xffU)) | ipaccess[ips].mask.__in6_u.__u6_addr8[i];
              iVar3 = shift;
              if (shift != 0) {
                iVar3 = 0;
              }
              cVar7 = (char)iVar3;
              if (shift == 0) {
                cVar7 = '\x01';
              }
              shift = shift + -1;
              if (cVar7 != '\0') {
                i = i + 1;
                shift = 7;
              }
            }
            goto LAB_000127d6;
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

