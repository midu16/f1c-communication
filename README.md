# F1-Control Plane 3GPP 

## Scope

The scope of this repo its to implement the F1-C Interface communication based on `3GPP TS 38.473` standard.

![Figure 1: F1 Interface](./images/figure1.png)


- [F1-Control Plane 3GPP](#f1-control-plane-3gpp)
  - [Scope](#scope)
  - [Client side](#client-side)
  - [Server side](#server-side)
  - [`tcpdump` package flow](#tcpdump-package-flow)


## Client side
```bash
$ go run cmd/cu/main.go -server=192.168.1.20:38473
2025/01/07 00:34:37 Starting CU client, connecting to server at 192.168.1.20:38473...
Connected to DU server at 192.168.1.20:38473
Received response: {MessageType:Response Payload:Acknowledged: Hello DU 1}
Received response: {MessageType:Response Payload:Acknowledged: Hello DU 2}
Received response: {MessageType:Response Payload:Acknowledged: Hello DU 3}
Received response: {MessageType:Response Payload:Acknowledged: Hello DU 4}
Received response: {MessageType:Response Payload:Acknowledged: Hello DU 5}
```

## Server side
```bash
$ go run cmd/du/main.go
2025/01/07 00:25:28 Starting DU server...
DU Server listening on :38473
Client connected: 192.168.1.22:60446
Received message: {MessageType:Request Payload:Hello DU 1}
Received message: {MessageType:Request Payload:Hello DU 2}
Received message: {MessageType:Request Payload:Hello DU 3}
Received message: {MessageType:Request Payload:Hello DU 4}
Received message: {MessageType:Request Payload:Hello DU 5}
Connection closed by client: EOF
```

## `tcpdump` package flow

```bash
$ sudo tcpdump -i eth0 port 38473 -A
tcpdump: verbose output suppressed, use -v[v]... for full protocol decode
listening on eth0, link-type EN10MB (Ethernet), snapshot length 262144 bytes
00:43:07.273212 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [S], seq 1777628751, win 64240, options [mss 1460,sackOK,TS val 2296879123 ecr 0,nop,wscale 10], length 0
E..<e.@.@.Q..........z.Ii.vO...................
...........

00:43:07.273399 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [S.], seq 2336203699, ack 1777628752, win 65160, options [mss 1460,sackOK,TS val 4273157428 ecr 2296879123,nop,wscale 7], length 0
E..<..@.@..A.........I.z.?..i.vP...............
..54........
00:43:07.273425 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [.], ack 1, win 63, options [nop,nop,TS val 2296879123 ecr 4273157428], length 0
E..4e.@.@.Q..........z.Ii.vP.?.....?.......
......54
00:43:07.273516 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [P.], seq 1:51, ack 1, win 63, options [nop,nop,TS val 2296879123 ecr 4273157428], length 50
E..fe.@.@.Q..........z.Ii.vP.?.....?.......
......54{"message_type":"Request","payload":"Hello DU 1"}

00:43:07.273680 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [.], ack 51, win 509, options [nop,nop,TS val 4273157428 ecr 2296879123], length 0
E..4.8@.@.0..........I.z.?..i.v.....E3.....
..54....
00:43:07.273795 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [P.], seq 1:66, ack 51, win 509, options [nop,nop,TS val 4273157428 ecr 2296879123], length 65
E..u.9@.@./..........I.z.?..i.v............
..54....{"message_type":"Response","payload":"Acknowledged: Hello DU 1"}

00:43:07.273802 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [.], ack 66, win 63, options [nop,nop,TS val 2296879124 ecr 4273157428], length 0
E..4e.@.@.Q..........z.Ii.v..?.....?.......
......54
00:43:07.273843 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [P.], seq 51:101, ack 66, win 63, options [nop,nop,TS val 2296879124 ecr 4273157428], length 50
E..fe.@.@.Q..........z.Ii.v..?.....?.......
......54{"message_type":"Request","payload":"Hello DU 2"}

00:43:07.274008 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [P.], seq 66:131, ack 101, win 509, options [nop,nop,TS val 4273157428 ecr 2296879124], length 65
E..u.:@.@./..........I.z.?..i.v............
..54....{"message_type":"Response","payload":"Acknowledged: Hello DU 2"}

00:43:07.274031 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [P.], seq 101:151, ack 131, win 63, options [nop,nop,TS val 2296879124 ecr 4273157428], length 50
E..fe.@.@.Q..........z.Ii.v..?.6...?.......
......54{"message_type":"Request","payload":"Hello DU 3"}

00:43:07.274235 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [P.], seq 131:196, ack 151, win 509, options [nop,nop,TS val 4273157428 ecr 2296879124], length 65
E..u.;@.@./..........I.z.?.6i.v......4.....
..54....{"message_type":"Response","payload":"Acknowledged: Hello DU 3"}

00:43:07.274254 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [P.], seq 151:201, ack 196, win 63, options [nop,nop,TS val 2296879124 ecr 4273157428], length 50
E..fe.@.@.Q..........z.Ii.v..?.w...?.......
......54{"message_type":"Request","payload":"Hello DU 4"}

00:43:07.274458 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [P.], seq 196:261, ack 201, win 509, options [nop,nop,TS val 4273157429 ecr 2296879124], length 65
E..u.<@.@./..........I.z.?.wi.w............
..55....{"message_type":"Response","payload":"Acknowledged: Hello DU 4"}

00:43:07.274476 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [P.], seq 201:251, ack 261, win 63, options [nop,nop,TS val 2296879124 ecr 4273157429], length 50
E..fe.@.@.Q..........z.Ii.w..?.....?.......
......55{"message_type":"Request","payload":"Hello DU 5"}

00:43:07.274674 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [P.], seq 261:326, ack 251, win 509, options [nop,nop,TS val 4273157429 ecr 2296879124], length 65
E..u.=@.@./..........I.z.?..i.wJ.....K.....
..55....{"message_type":"Response","payload":"Acknowledged: Hello DU 5"}

00:43:07.274698 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [F.], seq 251, ack 326, win 63, options [nop,nop,TS val 2296879125 ecr 4273157429], length 0
E..4e.@.@.Q..........z.Ii.wJ.?.....?.......
......55
00:43:07.274890 IP 192.168.1.20.38473 > 192.168.1.22.45434: Flags [F.], seq 326, ack 252, win 509, options [nop,nop,TS val 4273157429 ecr 2296879125], length 0
E..4.>@.@.0..........I.z.?..i.wK....C!.....
..55....
00:43:07.274901 IP 192.168.1.22.45434 > 192.168.1.20.38473: Flags [.], ack 327, win 63, options [nop,nop,TS val 2296879125 ecr 4273157429], length 0
E..4e.@.@.Q..........z.Ii.wK.?.....?.......
......55
```