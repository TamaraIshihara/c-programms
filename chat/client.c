#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

void alloc_buf(uv_handle_t *handle, size_t  size, uv_buf_t *buf)
{
	buf->base = malloc(size);
	buf->len = size;
}

void on_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf)
{
	//printf("TRUE\n");	
	if(nread > 0)
	{
		const char *str = (const char* )buf->base;
		printf("%s\n", str);
	}
}

void on_connect(uv_connect_t *connect, int status)
{
	
	printf("Sucsessful connect\n");

	uv_read_start(connect->handle, alloc_buf, on_read);
			
}


int main(int argc, char* argv)
{
	uv_loop_t *loop = uv_default_loop();
	uv_tcp_t* socket = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
	uv_tcp_init(loop, socket);

	uv_connect_t* connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));

	struct sockaddr_in dest;
	uv_ip4_addr("192.168.1.127", 3001, &dest);

	uv_tcp_connect(connect, socket, (const struct sockaddr*)&dest, on_connect);

	return uv_run(loop, UV_RUN_DEFAULT);
}
