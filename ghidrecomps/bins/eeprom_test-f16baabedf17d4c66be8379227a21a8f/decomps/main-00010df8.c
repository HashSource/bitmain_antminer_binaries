
int main(int argc,char **argv)

{
  int iVar1;
  int iVar2;
  char **argv_local;
  int argc_local;
  uint8_t buf [256];
  char path [256];
  int fd;
  int i;
  uint8_t bom;
  uint8_t pcb;
  int len;
  int addr;
  uint8_t chain;
  int option;
  int ret;
  
  ret = 0;
  option = 0;
  if (((argv[1] == (char *)0x0) || (iVar1 = strcmp(argv[1],"--help"), iVar1 == 0)) ||
     (iVar1 = strcmp(argv[1],"-h"), iVar1 == 0)) {
    print_usage();
  }
  else {
    iVar1 = open("/dev/axi_fpga_dev",2);
    if (iVar1 < 0) {
      printf("/dev/axi_fpga_dev open failed. fd = %d\n",iVar1);
      perror("open");
      ret = -1;
    }
    else {
      axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,iVar1,0);
      if (axi_fpga_addr == (uint *)0x0) {
        printf("mmap axi_fpga_addr failed. axi_fpga_addr = 0x%lsx\n",0);
        ret = -1;
      }
      else {
        chain_num = check_chain_num();
        iVar2 = strcmp(argv[1],"-d");
        if (iVar2 == 0) {
          if (argc == 3) {
            iVar2 = atoi(argv[2]);
            chain = (uint8_t)iVar2;
            option = 1;
          }
        }
        else {
          iVar2 = strcmp(argv[1],"-l");
          if (iVar2 == 0) {
            if (argc == 3) {
              iVar2 = atoi(argv[2]);
              chain = (uint8_t)iVar2;
              option = 2;
            }
          }
          else {
            iVar2 = strcmp(argv[1],"-i");
            if (iVar2 == 0) {
              if (argc == 3) {
                strcpy(path,argv[2]);
                option = 3;
              }
            }
            else {
              iVar2 = strcmp(argv[1],"-e");
              if (iVar2 == 0) {
                if (argc == 3) {
                  iVar2 = atoi(argv[2]);
                  chain = (uint8_t)iVar2;
                  option = 4;
                }
              }
              else {
                iVar2 = strcmp(argv[1],"-w");
                if (iVar2 == 0) {
                  if (3 < argc) {
                    iVar2 = atoi(argv[2]);
                    chain = (uint8_t)iVar2;
                    addr = atoi(argv[3]);
                    len = argc + -4;
                    for (i = 0; i < len; i = i + 1) {
                      iVar2 = atoi(argv[i + 4]);
                      buf[i] = (uint8_t)iVar2;
                    }
                    option = 5;
                  }
                }
                else {
                  iVar2 = strcmp(argv[1],"-r");
                  if (iVar2 == 0) {
                    if (argc == 5) {
                      iVar2 = atoi(argv[2]);
                      chain = (uint8_t)iVar2;
                      addr = atoi(argv[3]);
                      len = atoi(argv[4]);
                      option = 6;
                    }
                  }
                  else {
                    iVar2 = strcmp(argv[1],"-p");
                    if ((iVar2 == 0) && (argc == 5)) {
                      iVar2 = atoi(argv[2]);
                      chain = (uint8_t)iVar2;
                      iVar2 = atoi(argv[3]);
                      pcb = (uint8_t)iVar2;
                      iVar2 = atoi(argv[4]);
                      bom = (uint8_t)iVar2;
                      option = 7;
                    }
                  }
                }
              }
            }
          }
        }
        switch(option) {
        case 0:
          print_usage();
          ret = 0;
          break;
        case 1:
          ret = dump_eeprom(chain);
          break;
        case 2:
          ret = tarverse_eeprom(chain);
          break;
        case 3:
          ret = init_eeprom_all(path);
          break;
        case 4:
          ret = erase_eeprom(chain);
          break;
        case 5:
          ret = write_eeprom(chain,addr,buf,len);
          break;
        case 6:
          ret = read_eeprom(chain,addr,len);
          break;
        case 7:
          ret = update_version_info(chain,pcb,bom);
          break;
        default:
          print_usage();
          ret = 0;
        }
        pthread_mutex_destroy((pthread_mutex_t *)&iic_mutex);
        munmap(axi_fpga_addr,0x160);
        close(iVar1);
      }
    }
  }
  return ret;
}

