  
  
 

/**************************************************************************************** 
*
* This code was generated by the Command Creator tool for the ChainsAPM project. 
* If manual changes are made to the code they could be lost.
*
****************************************************************************************/
#pragma once
#include "stdafx.h"
#include "commands\ACK.h"
 

namespace Commands
{
	ACK::ACK(__int64 timestamp, __int64 commandtimestamp, __int16 commandnumber)
		: timestamp(timestamp), code(0x0002), hasEncoded(false), CommandTimeStamp(commandtimestamp), CommandNumber(commandnumber) 
	{
	}

	ACK::~ACK()
	{
	}

	std::wstring ACK::Name()
	{
		return L"ACK";
	}

	std::wstring ACK::Description()
	{
		return L"Acknowledge Command";
	}

	std::shared_ptr<std::vector<char>> ACK::Encode()
	{
		if (!hasEncoded)
		{
			// The following items will be resued 
			auto hash = std::hash<std::wstring>();
			size_t hashout = 0;		// Temp var for string hashes
			size_t strlen = 0;		// Temp var for string length
			size_t strbytes = 0;	// Temp var for string bytes

			size_t size = sizeof(__int32)	// len
				+ sizeof(short)				// code
				+ sizeof(__int64);			// timestamp

			// Begin the dynamically generated sizes
			size += sizeof(__int64); // Size of CommandTimeStamp
			
			size += sizeof(__int16); // Size of CommandNumber
			
			// End the dynamically generated sizes  
			size += sizeof(short);	//Terminator

			auto vector = new char[size]; 
			short term = 0;
			
			// 
			auto v2 = (char*)memcpy(vector, &size, sizeof(__int32));  
			v2 += sizeof(__int32); 
			memcpy(v2, &code, sizeof(short));
			v2 += sizeof(short);
			memcpy(v2, &timestamp, sizeof(__int64));
			v2 += sizeof(__int64);

			// Begin the dynamically generated byte copies    
			memcpy(v2, &CommandTimeStamp, sizeof(__int64));  
			v2 += sizeof(__int64); memcpy(v2, &CommandNumber, sizeof(__int16));  
			v2 += sizeof(__int16); 			// End the dynamically generated byte copies

			// Terminator
			memcpy(v2, &term, sizeof(short));
			v2 += sizeof(short);

			hasEncoded = true;

			internalvector = std::make_shared<std::vector<char>>(vector, v2);
		}
		return internalvector;
	}

	std::shared_ptr<ICommand> ACK::Decode(std::shared_ptr<std::vector<char>> &data)      
	{
		auto hash = std::hash<std::wstring>();

		auto ptr = data->data();

		auto len = *(unsigned int*)ptr;  
		ptr += sizeof(unsigned int);

		auto code = *(short*)ptr;
		ptr += sizeof(short);

		auto local_timestamp = *(__int64*)ptr;
		ptr += sizeof(__int64);

		auto local_CommandTimeStamp = *(__int64*)ptr;  
		ptr += sizeof(__int64); 
		auto local_CommandNumber = *(__int16*)ptr;  
		ptr += sizeof(__int16); 

		// Terminator
		auto term = *(short*)ptr;
		ptr += sizeof(short);
		return std::make_shared<ACK>(local_timestamp,  local_CommandTimeStamp ,  local_CommandNumber );
	}
}

