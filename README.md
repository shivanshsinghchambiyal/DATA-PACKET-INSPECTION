# Deep Packet Inspection (DPI) Engine Simulator

A C++-based Deep Packet Inspection (DPI) Engine Simulator that analyzes network traffic, identifies applications using Domain/SNI information, applies user-defined filtering rules, and generates detailed packet processing reports.

## Project Description

Deep Packet Inspection (DPI) is a network traffic analysis technique used by firewalls and security systems to inspect packet information and enforce security policies.

This project simulates the core functionality of a DPI engine by inspecting packet metadata such as domain names, protocols, and packet sizes. Based on user-defined blocking rules, the engine decides whether packets should be forwarded or dropped and generates traffic statistics for monitoring and analysis.

## Features

- Domain/SNI Inspection
- User-Defined Blocking Rules
- Application Detection
- TCP and UDP Traffic Analysis
- Packet Filtering (Forward / Drop)
- Total Packet Monitoring
- Total Traffic Byte Monitoring
- Traffic Statistics Generation
- Domain Identification and Reporting
- Firewall-Style Console Interface

## Supported Application Detection

The engine can identify traffic associated with:

- YouTube
- Facebook
- Google
- GitHub
- Unknown Applications

## Workflow

```text
User Rules
     │
     ▼
Packet Arrival
     │
     ▼
Domain/SNI Inspection
     │
     ▼
Application Detection
     │
     ▼
Rule Matching
     │
 ┌───┴───┐
 │       │
 ▼       ▼
DROP   FORWARD
 │       │
 └───┬───┘
     ▼
Statistics Report
```

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- Unordered Maps
- Unordered Sets
- Networking Concepts
- Packet Inspection Logic

## Example Output

```text
====================================================
          DPI ENGINE v2.0
====================================================

[Rules] Blocked app: youtube
[Rules] Blocked app: facebook

[Reader] Processing packets...
[Reader] Done reading 77 packets

[Detected Domains/SNIs]

 - www.youtube.com -> YouTube
 - www.facebook.com -> Facebook
 - www.google.com -> Google
 - github.com -> GitHub

====================================================
                 PROCESSING REPORT
====================================================

Total Packets: 77
Total Bytes: 5738

TCP Packets: 73
UDP Packets: 4

Forwarded: 69
Dropped: 8

====================================================
```

## Concepts Demonstrated

- Deep Packet Inspection (DPI)
- Firewall Rule Enforcement
- Traffic Filtering
- Packet Analysis
- Domain-Based Blocking
- Application Identification
- Network Monitoring
- Traffic Statistics Collection

## Learning Outcomes

This project helped in understanding:

- How DPI systems inspect network traffic
- How firewalls apply filtering rules
- Packet processing workflows
- Traffic monitoring and reporting
- Efficient data management using STL containers
- Design of modular C++ applications

## Future Enhancements

- Real Packet Capture using PCAP/Npcap
- Multi-threaded Packet Processing
- IP-Based Filtering
- Port-Based Filtering
- Protocol-Based Rules
- Real-Time Traffic Monitoring
- Traffic Logging
- Dashboard Visualization
- Packet Queue Management



Developed as a networking and cybersecurity project to demonstrate packet inspection, traffic filtering, and rule-based traffic management using C++.
