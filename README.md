# Description
解决了 time.sleep 占用cpu过少的问题（赤石代码）

# Install
`pip install .`

# Usage
``` python
from better_sleep import better_sleep
better_sleep(10, 5) # sleep 10 seconds with 5 heavy threads.
```
