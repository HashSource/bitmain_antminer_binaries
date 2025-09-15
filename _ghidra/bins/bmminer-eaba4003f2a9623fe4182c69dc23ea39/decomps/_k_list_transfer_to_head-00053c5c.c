
void _k_list_transfer_to_head(K_LIST *from,K_LIST *to,char *file,char *func,int line)

{
  char *func_local;
  char *file_local;
  K_LIST *to_local;
  K_LIST *from_local;
  char tmp42 [2048];
  
  if (from->name != to->name) {
    snprintf(tmp42,0x800,"List %s can\'t %s() to a %s list - from %s %s() line %d in %s %s():%d",
             from->name,"_k_list_transfer_to_head",to->name,file,func,line,"klist.c",
             "_k_list_transfer_to_head",0x152);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (from->do_tail != true) {
    snprintf(tmp42,0x800,
             "List %s can\'t %s() - do_tail is false - from %s %s() line %d in %s %s():%d",
             from->name,"_k_list_transfer_to_head",file,func,line,"klist.c",
             "_k_list_transfer_to_head",0x157);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (from->head != (k_item *)0x0) {
    if (to->head == (k_item *)0x0) {
      to->tail = from->tail;
    }
    else {
      to->head->prev = from->tail;
    }
    from->tail->next = to->head;
    to->head = from->head;
    from->tail = (k_item *)0x0;
    from->head = from->tail;
    to->count = to->count + from->count;
    from->count = 0;
    to->count_up = to->count_up + from->count_up;
    from->count_up = 0;
  }
  return;
}

