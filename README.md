# DATA-PACKET-INSPECTION
This project is a C++-based Data Packet Inspection (DPI) Engine that simulates the behavior of a network security system used to monitor and control network traffic. The primary objective of the project is to inspect incoming packets, analyze their attributes, and make forwarding or blocking decisions based on predefined firewall rules.
# Features-
 1. Packet Inspection and Analysis
 2. Domain/SNI Detection
 3. Application Identification (YouTube, Facebook, Google, GitHub, etc.)
 4. User-Defined Blocking Rules
 5. TCP and UDP Traffic Statistics
 6. Forwarded and Dropped Packet Tracking
 7. Total Packet and Byte Monitoring
 8. Real-Time Traffic Processing Reports
 9. Firewall-Style Console Output
# How It Works-
-The user defines blocking rules for specific domains or applications.
-The DPI engine processes incoming packets.
-Each packet is inspected using its Domain/SNI information.
-The engine identifies the corresponding application.
-Blocking rules are applied:
-Matching packets are dropped.
-Non-matching packets are forwarded.
-A final report is generated showing traffic statistics and inspection results.
# Technologies Used-
-C++
-Object-Oriented Programming (OOP)
-Standard Template Library (STL)
-unordered_map
-unordered_set
-Networking Concepts
-Packet Inspection
-SNI (Server Name Indication)
-TCP/UDP Protocol Analysis
-Traffic Filtering
