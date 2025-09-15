
int parse_one(int *argc,char **argv,uint *offset,_func_void_char_ptr_varargs *errlog)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  _func_void_char_ptr_varargs *errlog_local;
  uint *offset_local;
  char **argv_local;
  int *argc_local;
  uint len;
  uint i;
  char *problem;
  char *optarg;
  char *o;
  uint arg;
  
  optarg = (char *)0x0;
  pcVar1 = getenv("POSIXLY_CORRECT");
  if (pcVar1 == (char *)0x0) {
    for (arg = 1; (argv[arg] != (char *)0x0 && (*argv[arg] != '-')); arg = arg + 1) {
    }
  }
  else {
    arg = 1;
  }
  if ((argv[arg] == (char *)0x0) || (*argv[arg] != '-')) {
    iVar3 = 0;
  }
  else {
    iVar3 = strcmp(argv[arg],"--");
    if (iVar3 == 0) {
      consume_option(argc,argv,arg);
      iVar3 = 0;
    }
    else {
      if (argv[arg][1] == '-') {
        if (*offset != 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("*offset == 0","ccan/opt/parse.c",0x3b,"parse_one");
        }
        for (o = first_lopt(&i,&len); o != (char *)0x0; o = next_lopt(o,&i,&len)) {
          iVar3 = strncmp(argv[arg] + 2,o,len);
          if (iVar3 == 0) {
            if (argv[arg][len + 2] == '=') {
              optarg = argv[arg] + len + 3;
              break;
            }
            if (argv[arg][len + 2] == '\0') break;
          }
        }
        if (o == (char *)0x0) {
          pcVar4 = *argv;
          pcVar1 = argv[arg];
          sVar2 = strlen(argv[arg]);
          iVar3 = parse_err(errlog,pcVar4,pcVar1,sVar2,"unrecognized option");
          return iVar3;
        }
        o = o + -2;
        len = len + 2;
      }
      else {
        for (o = first_sopt(&i); o != (char *)0x0; o = next_sopt(o,&i)) {
          if (argv[arg][*offset + 1] == *o) {
            *offset = *offset + 1;
            break;
          }
        }
        if (o == (char *)0x0) {
          pcVar4 = *argv;
          pcVar1 = argv[arg];
          sVar2 = strlen(argv[arg]);
          iVar3 = parse_err(errlog,pcVar4,pcVar1,sVar2,"unrecognized option");
          return iVar3;
        }
        o = o + -1;
        len = 2;
      }
      if (opt_table[i].type == OPT_NOARG) {
        if (optarg != (char *)0x0) {
          iVar3 = parse_err(errlog,*argv,o,len,"doesn\'t allow an argument");
          return iVar3;
        }
        problem = (*opt_table[i].cb)(opt_table[i].u.carg);
      }
      else {
        if (optarg == (char *)0x0) {
          if ((*offset == 0) || (argv[arg][*offset + 1] == '\0')) {
            optarg = argv[arg + 1];
          }
          else {
            optarg = argv[arg] + *offset + 1;
            *offset = 0;
          }
        }
        if (optarg == (char *)0x0) {
          iVar3 = parse_err(errlog,*argv,o,len,"requires an argument");
          return iVar3;
        }
        if (opt_table[i].type == OPT_PROCESSARG) {
          opt_set_charp(optarg,(char **)opt_table[i].u.carg);
        }
        problem = (*opt_table[i].cb_arg)(optarg,opt_table[i].u.carg);
      }
      if (problem == (char *)0x0) {
        if ((*offset != 0) && (argv[arg][*offset + 1] == '\0')) {
          *offset = 0;
        }
        if (((*offset == 0) && (consume_option(argc,argv,arg), optarg != (char *)0x0)) &&
           (argv[arg] == optarg)) {
          consume_option(argc,argv,arg);
        }
        iVar3 = 1;
      }
      else {
        parse_err(errlog,*argv,o,len,problem);
        free(problem);
        iVar3 = -1;
      }
    }
  }
  return iVar3;
}

