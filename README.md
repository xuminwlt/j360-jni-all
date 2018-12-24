JNI服务端多媒体处理


## Bridge compile

```shell
$ mvn package
$ mkdir jni
$ cd jni
$ javah -cp ../target/classes/ me.j360.jni.bridge.ImageBridge
```


## Lib Compile

Linux
```
gcc -shared -fpic -I$JAVA_HOME/include -I$JAVA_HOME/include/linux ImageBridge.c -o libImageBridge.so
```

MaxOS
```
gcc -shared -fpic -I$JAVA_HOME/include -I$JAVA_HOME/include/darwin ImageBridge.c -o libImageBridge.dylib
```

## Run

- Linux环境
系统变量LD_LIBRARY_PATH来添加java.library.path

- Windows
在系统->高级系统设置->环境变量里，在path变量里添加。

- Eclipse
在Properties -> Run/Debug settings -> Arguments->VM arguments里添加：

    -Djava.library.path=/usr/java/local

- IntelliJ Idea
Run/Debug Configurations的VM Options里添加：

    -Djava.library.path=/usr/java/local

- 程序动态添加
private static void loadJNILibDynamically() {
        try {
            System.setProperty("java.library.path", System.getProperty("java.library.path")
                    + ":/usr/java/local/");
            Field fieldSysPath = ClassLoader.class.getDeclaredField("sys_paths");
            fieldSysPath.setAccessible(true);
            fieldSysPath.set(null, null);
 
            System.loadLibrary("ImageBridge");
        } catch (Exception e) {
            // do nothing for exception
        }
    }
