
/* ===== Helpers ===== */

static void print_queue(const tQueue *q) {
    printf("Queue(size=%d, cap=%d) [", q->nelem, MAX);
    for (int i = 0; i < q->nelem; i++) {
        printf("%d", q->vector[i]);
        if (i < q->nelem - 1) printf(", ");
    }
    printf("]\n");
}

static void log_status(const char *tag, const tQueue *q) {
    int front;

    printf("\n[%s]\n", tag);
    printf("  empty=%s  full=%s  size=%d\n",
           isEmptyQueue(*q) ? "true" : "false",
           isFullQueue(*q)  ? "true" : "false",
           lengthQueue(*q));

    if (head(q, &front))
        printf("  head=%d\n", front);
    else
        printf("  head=(none)\n");

    printf("  ");
    print_queue(q);
}

static void log_enqueue(tQueue *q, int value) {
    printf("\n> enqueue(%d)\n", value);

    if (isFullQueue(*q)) {
        printf("  FAIL: queue is full\n");
    } else {
        enqueue(q, value);
        printf("  OK: inserted %d\n", value);
    }

    log_status("after enqueue", q);
}

static void log_dequeue(tQueue *q) {
    int removed;

    printf("\n> dequeue()\n");

    if (isEmptyQueue(*q)) {
        printf("  FAIL: queue is empty\n");
    } else {
        head(q, &removed);
        dequeue(q);
        printf("  OK: removed %d\n", removed);
    }

    log_status("after dequeue", q);
}
