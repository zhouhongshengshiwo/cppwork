
const path = require('path')//引入path模块相对于include
const grpc = require('@grpc/grpc-js')
const protoLoader = require('@grpc/proto-loader')

//将当前目录的路径和 message.proto 文件名连接，生成一个指向 protobuf 文件的完整路径。
const PROTO_PATH = path.join(__dirname, 'message.proto')
//使用 protoLoader 加载 protobuf 文件，生成一个 protobuf 定义对象。
const packageDefinition = protoLoader.loadSync(PROTO_PATH, { keepCase: true, longs: String, enums: String, defaults: true, oneofs: true })
//使用 grpc.loadPackageDefinition 方法加载 protobuf 定义对象，生成一个包含 protobuf 类型定义的对象。
const protoDescriptor = grpc.loadPackageDefinition(packageDefinition)
//从 protobuf 定义对象中获取 message 类型定义对象。
const message_proto = protoDescriptor.message
//导出 message 类型定义对象。
module.exports = message_proto