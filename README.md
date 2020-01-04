# 第1章 容器与开发语言
## Dock常用命令
### 查看docker服务
* 查看docker状态
> docker info
* 故障检测
> sudo service docker status
### 镜像
* 列出本机所有镜像
> docker images
* 从dockerhub检索镜像
> docker search <image_name>
* 下载image
> docker pull <image_name>
* 删除镜像
> docker rm <image_name>
### 从镜像启动一个新的容器
* 启动容器并启动bash，例如：image_name = ubuntu
> docker run -i -t <image_name> /bin/bash
    - -i标志保证容器中的STDIN是开启的
    - -t标志告诉Docker要为创建的容器分配一个伪tty终端
* 启动容器后台方式运行(更通用)
> docker run -d -it <image_name>
### 容器
* 列出所有正在运行的container
> docker ps
* 列出所有container
> docker ps -a
### 附着到容器
* 附着到正在运行的容器
> docker attach <container_name/ID>
* 进入正在运行的容器内部，同时运行bash(比attach好用)
> docker exec -t -i <container_name/ID> /bin/bash
### 操作现有容器
* 重新启动容器
> docker start <container_name/ID>
* 停止启动的容器
> docker stop <container_name/ID>
* 显示一个运行的容器里面的进程信息
> docker top <container_name/ID>
* 从容器里拷贝文件到本地路径
> docker cp <container_name:/container_path> <to_path>
* 查看容器日志
> docker logs <container_name/ID>
* 实时查看日志输出
> docker logs -f <container_name/ID> (类似 tail -f, 带上时间戳-t)
* 其他
```
> docker kill <container_name/ID>
> docker restart <container_name/ID>
> docker rm <container_name/ID>
```