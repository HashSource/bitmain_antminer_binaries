
void _opt_register(char *names,opt_type type,_func_char_ptr_void_ptr *cb,
                  _func_char_ptr_char_ptr_void_ptr *cb_arg,_func_void_char_ptr_void_ptr *show,
                  void *arg,char *desc)

{
  _func_char_ptr_char_ptr_void_ptr *cb_arg_local;
  _func_char_ptr_void_ptr *cb_local;
  opt_type type_local;
  char *names_local;
  opt_table opt;
  
  opt.show = show;
  opt.u.carg = arg;
  opt.desc = desc;
  opt.names = names;
  opt.type = type;
  opt.cb = cb;
  opt.cb_arg = cb_arg;
  check_opt(&opt);
  add_opt(&opt);
  return;
}

