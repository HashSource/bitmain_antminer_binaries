
void hashtable_close(hashtable_t *hashtable)

{
  hashtable_t *hashtable_local;
  
  hashtable_do_clear(hashtable);
  jsonp_free(hashtable->buckets);
  return;
}

