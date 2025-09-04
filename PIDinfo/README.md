# Get Info PID

```bash
    # 
    lsof -p 910O
    
   ps -o pid=,ppid=,stat=,ni,cmd= --no-headers | awk '{print $1, $2}' 
```

