#if defined _amxx_stocks_included
  #endinput
#endif
#define _amxx_stocks_included

#include <amxx>


/* Stocks for dhudmessage */

stock __dhud_color;
stock __dhud_x;
stock __dhud_y;
stock __dhud_effect;
stock __dhud_fxtime;
stock __dhud_holdtime;
stock __dhud_fadeintime;
stock __dhud_fadeouttime;
stock __dhud_reliable

/* CS Weapons Bits */

const CSW_ALL_WEAPONS      = (~(1<<CSW_VEST));
const CSW_ALL_PISTOLS      = (1<<CSW_P228  | 1<<CSW_ELITE | 1<<CSW_FIVESEVEN | 1<<CSW_USP | 1<<CSW_GLOCK18 | 1<<CSW_DEAGLE);
const CSW_ALL_SHOTGUNS     = (1<<CSW_M3    | 1<<CSW_XM1014);
const CSW_ALL_SMGS         = (1<<CSW_MAC10 | 1<<CSW_UMP45 | 1<<CSW_MP5NAVY | 1<<CSW_TMP  | 1<<CSW_P90);
const CSW_ALL_RIFLES       = (1<<CSW_AUG   | 1<<CSW_GALIL | 1<<CSW_FAMAS   | 1<<CSW_M4A1 | 1<<CSW_AK47 | 1<<CSW_SG552);
const CSW_ALL_SNIPERRIFLES = (1<<CSW_SCOUT | 1<<CSW_AWP   | 1<<CSW_G3SG1   | 1<<CSW_SG550);
const CSW_ALL_MACHINEGUNS  = (1<<CSW_M249);
const CSW_ALL_GRENADES     = (1<<CSW_HEGRENADE | 1<<CSW_SMOKEGRENADE | 1<<CSW_FLASHBANG);
const CSW_ALL_ARMORS       = (1<<CSW_VEST | 1<<CSW_VESTHELM);
const CSW_ALL_GUNS         = (CSW_ALL_PISTOLS | CSW_ALL_SHOTGUNS | CSW_ALL_SMGS | CSW_ALL_RIFLES | CSW_ALL_SNIPERRIFLES | CSW_ALL_MACHINEGUNS);


/**
 * Weapon default cost.
 */
enum CsWeaponCostType
{
	CS_AK47_PRICE      = 2500,
	CS_AWP_PRICE       = 4750,
	CS_DEAGLE_PRICE    = 650,
	CS_G3SG1_PRICE     = 5000,
	CS_SG550_PRICE     = 4200,
	CS_GLOCK18_PRICE   = 400,
	CS_M249_PRICE      = 5750,
	CS_M3_PRICE        = 1700,
	CS_M4A1_PRICE      = 3100,
	CS_AUG_PRICE       = 3500,
	CS_MP5NAVY_PRICE   = 1500,
	CS_P228_PRICE      = 600,
	CS_P90_PRICE       = 2350,
	CS_UMP45_PRICE     = 1700,
	CS_MAC10_PRICE     = 1400,
	CS_SCOUT_PRICE     = 2750,
	CS_SG552_PRICE     = 3500,
	CS_TMP_PRICE       = 1250,
	CS_USP_PRICE       = 500,
	CS_ELITE_PRICE     = 800,
	CS_FIVESEVEN_PRICE = 750,
	CS_XM1014_PRICE    = 3000,
	CS_GALIL_PRICE     = 2000,
	CS_FAMAS_PRICE     = 2250,
	CS_SHIELDGUN_PRICE = 2200
};

/**
 * Equipment default cost.
 */
enum CsItemCostType
{
	CS_ASSAULTSUIT_PRICE  = 1000,
	CS_FLASHBANG_PRICE    = 200,
	CS_HEGRENADE_PRICE    = 300,
	CS_SMOKEGRENADE_PRICE = 300,
	CS_KEVLAR_PRICE       = 650,
	CS_HELMET_PRICE       = 350,
	CS_NVG_PRICE          = 1250,
	CS_DEFUSEKIT_PRICE    = 200
};

/**
 * Ammo default cost.
 */
enum CsAmmoCostType
{
	CS_AMMO_338MAG_PRICE   = 125,
	CS_AMMO_357SIG_PRICE   = 50,
	CS_AMMO_45ACP_PRICE    = 25,
	CS_AMMO_50AE_PRICE     = 40,
	CS_AMMO_556NATO_PRICE  = 60,
	CS_AMMO_57MM_PRICE     = 50,
	CS_AMMO_762NATO_PRICE  = 80,
	CS_AMMO_9MM_PRICE      = 20,
	CS_AMMO_BUCKSHOT_PRICE = 65
};

/* Macross to check Weapon entity class, "weaponbox"/"armoury_entity"/"weapon_shield" */

#define IsArmoury(%1)		(%1[0]=='a'&&%1[1]=='r'&&%1[7]=='_'&&%1[8]=='e'&&%1[12]=='t'&&%1[13]=='y')  
#define IsWpBox(%1)		(%1[0]=='w'&&%1[1]=='e'&&%1[5]=='n'&&%1[7]=='o'&&%1[8]=='x')
#define IsAShield(%1)		(%1[0]=='w'&&%1[1]=='e'&&%1[7]=='s'&&%1[8]=='h'&&%1[9]=='i'&&%1[11]=='l'&&%1[12]=='d')

/* Macross to check map prefix */

#define IsMapDe(%1)		(%1[0]=='d'&&%1[1]=='e'&&%1[2]=='_')
#define IsMapCs(%1)		(%1[0]=='c'&&%1[1]=='s'&&%1[2]=='_')
#define IsMapZm(%1)		(%1[0]=='z'&&%1[1]=='m'&&%1[2]=='_')

/* Macross for print_colored_message */
#define RED	Red
#define BLUE	Blue
#define GREY	Grey

#define FFADE_IN		0x0000			// Just here so we don't pass 0 into the function
#define FFADE_OUT		0x0001			// Fade out (not in)
#define FFADE_MODULATE		0x0002			// Modulate (don't blend)
#define FFADE_STAYOUT		0x0004			// ignores the duration, stays faded out until new ScreenFade message received

enum 
{
	Grey = 33,
	Red,
	Blue
};


stock get_alive_players( bool:TeamFlags=false, Team=1 )
{
	new Players[32], Num;

	if( TeamFlags )
	{
		switch( Team )
		{
			case 1: get_players( Players,Num, "ae", "TERRORIST" );
			case 2: get_players( Players,Num, "ae", "CT" );	
		}
	}

	else
	{
		get_players( Players, Num, "a" );
	}

	return Num;

}

stock menu_timeout( PlayerId, iTime )
{
	set_task( float( iTime ), "bAMXXUCSMenuTimeOut", PlayerId );
}

public bAMXXUCSMenuTimeOut( PlayerId )
{
	menu_cancel( PlayerId );	 
	show_menu( PlayerId, 0, "^n", 1 );
}

stock FixedUnsigned16(Float:flValue, iScale)
{
	new iOutput;

	iOutput = floatround(flValue * iScale);

	if ( iOutput < 0 )
		iOutput = 0;

	if ( iOutput > 0xFFFF )
		iOutput = 0xFFFF;

	return iOutput;
}

stock UTIL_ScreenFade(id=0,iColor[3]={0,0,0},Float:flFxTime=-1.0,Float:flHoldTime=0.0,iAlpha=0,iFlags=FFADE_IN,bool:bReliable=false,bool:bExternal=false)
{
	if( id && !is_user_connected(id))
		return;

	new iFadeTime;
	if( flFxTime == -1.0 )
	{
		iFadeTime = 4;
	}
	else
	{
		iFadeTime = FixedUnsigned16( flFxTime , 1<<12 );
	}

	static gmsgScreenFade;
	if( !gmsgScreenFade )
	{
		gmsgScreenFade = get_user_msgid("ScreenFade");
	}

	new MSG_DEST;
	if( bReliable )
	{
		MSG_DEST = id ? MSG_ONE : MSG_ALL;
	}
	else
	{
		MSG_DEST = id ? MSG_ONE_UNRELIABLE : MSG_BROADCAST;
	}

	if( bExternal )
	{
		emessage_begin( MSG_DEST, gmsgScreenFade, _, id );
		ewrite_short( iFadeTime );
		ewrite_short( FixedUnsigned16( flHoldTime , 1<<12 ) );
		ewrite_short( iFlags );
		ewrite_byte( iColor[Red] );
		ewrite_byte( iColor[Green] );
		ewrite_byte( iColor[Blue] );
		ewrite_byte( iAlpha );
		emessage_end();
	}
	else
	{
		message_begin( MSG_DEST, gmsgScreenFade, _, id );
		write_short( iFadeTime );
		write_short( FixedUnsigned16( flHoldTime , 1<<12 ) );
		write_short( iFlags );
		write_byte( iColor[Red] );
		write_byte( iColor[Green] );
		write_byte( iColor[Blue] );
		write_byte( iAlpha );
		message_end();
	}
}

stock UTIL_FadeToBlack(id,Float:fxtime=3.0,bool:bReliable=false,bool:bExternal=false)
{
	UTIL_ScreenFade(id, _, fxtime, fxtime, 255, FFADE_OUT|FFADE_STAYOUT,bReliable,bExternal);
}


/* Example for clearing: CreateFog( id, .clear = true ); */
stock CreateFog ( const index = 0, const red = 127, const green = 127, const blue = 127, const Float:density_f = 0.001, bool:clear = false )
{
    static msgFog;
    
    if ( msgFog || ( msgFog = get_user_msgid( "Fog" ) ) )
    {
        new density = _:floatclamp( density_f, 0.0001, 0.25 ) * _:!clear;
        
        message_begin( index ? MSG_ONE_UNRELIABLE : MSG_BROADCAST, msgFog, .player = index );
        write_byte( clamp( red  , 0, 255 ) );
        write_byte( clamp( green, 0, 255 ) );
        write_byte( clamp( blue , 0, 255 ) );
        write_long( _:density );
        message_end();
    }
}

stock set_dhudmessage( red = 0, green = 160, blue = 0, Float:x = -1.0, Float:y = 0.65, effects = 2, Float:fxtime = 6.0, Float:holdtime = 3.0, Float:fadeintime = 0.1, Float:fadeouttime = 1.5, bool:reliable = false )
{
    #define clamp_byte(%1)       ( clamp( %1, 0, 255 ) )
    #define pack_color(%1,%2,%3) ( %3 + ( %2 << 8 ) + ( %1 << 16 ) )

    __dhud_color       = pack_color( clamp_byte( red ), clamp_byte( green ), clamp_byte( blue ) );
    __dhud_x           = _:x;
    __dhud_y           = _:y;
    __dhud_effect      = effects;
    __dhud_fxtime      = _:fxtime;
    __dhud_holdtime    = _:holdtime;
    __dhud_fadeintime  = _:fadeintime;
    __dhud_fadeouttime = _:fadeouttime;
    __dhud_reliable    = _:reliable;

    return 1;
}

stock show_dhudmessage( index, const message[], any:... )
{
    new buffer[ 128 ];
    new numArguments = numargs();

    if( numArguments == 2 )
    {
        send_dhudMessage( index, message );
    }
    else if( index || numArguments == 3 )
    {
        vformat( buffer, charsmax( buffer ), message, 3 );
        send_dhudMessage( index, buffer );
    }
    else
    {
        new playersList[ 32 ], numPlayers;
        get_players( playersList, numPlayers, "ch" );

        if( !numPlayers )
        {
            return 0;
        }

        new Array:handleArrayML = ArrayCreate();

        for( new i = 2, j; i < numArguments; i++ )
        {
            if( getarg( i ) == LANG_PLAYER )
            {
                while( ( buffer[ j ] = getarg( i + 1, j++ ) ) ) {}
                j = 0;

                if( GetLangTransKey( buffer ) != TransKey_Bad )
                {
                    ArrayPushCell( handleArrayML, i++ );
                }
            }
        }

        new size = ArraySize( handleArrayML );

        if( !size )
        {
            vformat( buffer, charsmax( buffer ), message, 3 );
            send_dhudMessage( index, buffer );
        }
        else
        {
            for( new i = 0, j; i < numPlayers; i++ )
            {
                index = playersList[ i ];

                for( j = 0; j < size; j++ )
                {
                    setarg( ArrayGetCell( handleArrayML, j ), 0, index );
                }

                vformat( buffer, charsmax( buffer ), message, 3 );
                send_dhudMessage( index, buffer );
            }
        }

        ArrayDestroy( handleArrayML );
    }

    return 1;
}

stock send_dhudMessage( const index, const message[] )
{
    message_begin( __dhud_reliable ? ( index ? MSG_ONE : MSG_ALL ) : ( index ? MSG_ONE_UNRELIABLE : MSG_BROADCAST ), SVC_DIRECTOR, _, index );
    {
        write_byte( strlen( message ) + 31 );
        write_byte( DRC_CMD_MESSAGE );
        write_byte( __dhud_effect );
        write_long( __dhud_color );
        write_long( __dhud_x );
        write_long( __dhud_y );
        write_long( __dhud_fadeintime );
        write_long( __dhud_fadeouttime );
        write_long( __dhud_holdtime );
        write_long( __dhud_fxtime );
        write_string( message );
    }
    message_end();
}

stock print_colored_message(id, sender, const fmt[], any:...)
{
	// check if id is different from 0
	if( id && !is_user_connected(id) )
	{
		return 0;
	}

	static const szTeamName[][] = 
	{
		"",
		"TERRORIST",
		"CT"
	};

	new szMessage[192];

	new iParams = numargs();
	// Specific player code
	if( id )
	{
		if( iParams == 3 )
		{
			copy(szMessage, charsmax(szMessage), fmt); // copy so message length doesn't exceed critical 192 value
		}
		else
		{
			vformat(szMessage, charsmax(szMessage), fmt, 4);
		}

		if( sender > Grey )
		{
			if( sender > Blue )
			{
				sender = id;
			}
			else
			{
				_CC_TeamInfo(id, sender, szTeamName[sender-Grey]);
			}
		}
		_CC_SayText(id, sender, szMessage);
	} 

	// Send message to all players
	else
	{
		// Figure out if at least 1 player is connected
		// so we don't execute useless useless code if not
		new iPlayers[32], iNum;
		get_players(iPlayers, iNum, "ch");
		if( !iNum )
		{
			return 0;
		}

		new iMlNumber, i, j;
		new Array:aStoreML = ArrayCreate();
		if( iParams >= 5 ) // ML can be used
		{
			for(j=3; j<iParams; j++)
			{
				// retrieve original param value and check if it's LANG_PLAYER value
				if( getarg(j) == LANG_PLAYER )
				{
					i=0;
					// as LANG_PLAYER == -1, check if next parm string is a registered language translation
					while( ( szMessage[ i ] = getarg( j + 1, i++ ) ) ) {}
					if( GetLangTransKey(szMessage) != TransKey_Bad )
					{
						// Store that arg as LANG_PLAYER so we can alter it later
						ArrayPushCell(aStoreML, j++);

						// Update ML array saire so we'll know 1st if ML is used,
						// 2nd how many args we have to alterate
						iMlNumber++;
					}
				}
			}
		}

		// If arraysize == 0, ML is not used
		// we can only send 1 MSG_ALL message if sender != 0
		if( !iMlNumber )
		{
			if( iParams == 3 )
			{
				copy(szMessage, charsmax(szMessage), fmt);
			}
			else
			{
				vformat(szMessage, charsmax(szMessage), fmt, 4);
			}
			if( 0 < sender < Blue ) // if 0 is passed, need to loop
			{
				if( sender > Grey )
				{
					_CC_TeamInfo(0, sender, szTeamName[sender-Grey]);
				}
				_CC_SayText(0, sender, szMessage);
				return 1;
			}
		}

		if( sender > Blue )
		{
			sender = 0; // use receiver index
		}

		for(--iNum; iNum>=0; iNum--)
		{
			id = iPlayers[iNum];

			if( iMlNumber )
			{
				for(j=0; j<iMlNumber; j++)
				{
					// Set all LANG_PLAYER args to player index ( = id )
					// so we can format the text for that specific player
					setarg(ArrayGetCell(aStoreML, j), _, id);
				}
				
				// format string for specific player
				vformat(szMessage, charsmax(szMessage), fmt, 4);
			}

			if( sender > Grey )
			{
				_CC_TeamInfo(id, sender, szTeamName[sender-Grey]);
			}
			_CC_SayText(id, sender, szMessage);
		}

		ArrayDestroy(aStoreML);
	}
	return 1;
}

stock _CC_TeamInfo(iReceiver, iSender, szTeam[])
{
	static iTeamInfo = 0;
	if( !iTeamInfo )
	{
		iTeamInfo = get_user_msgid("TeamInfo");
	}
	message_begin(iReceiver ? MSG_ONE : MSG_ALL, iTeamInfo, _, iReceiver);
	write_byte(iSender);
	write_string(szTeam);
	message_end();
}

stock _CC_SayText(iReceiver, iSender, szMessage[])
{
	static iSayText = 0;
	if( !iSayText )
	{
		iSayText = get_user_msgid("SayText");
	}
	message_begin(iReceiver ? MSG_ONE : MSG_ALL, iSayText, _, iReceiver);
	write_byte(iSender ? iSender : iReceiver);
	write_string(szMessage);
	message_end();
}

stock register_colored_dex(const filename[])
{
	if( !register_dictionary(filename) )
	{
		return 0;
	}

	new szFileName[256];
	get_localinfo("amxx_datadir", szFileName, charsmax(szFileName));
	format(szFileName, charsmax(szFileName), "%s/lang/%s", szFileName, filename);
	new fp = fopen(szFileName, "rt");
	if( !fp )
	{
		log_amx("Failed to open %s", szFileName);
		return 0;
	}

	new szBuffer[512], szLang[3], szKey[64], szTranslation[256], TransKey:iKey;

	while( !feof(fp) )
	{
		fgets(fp, szBuffer, charsmax(szBuffer));
		trim(szBuffer);

		if( szBuffer[0] == '[' )
		{
			strtok(szBuffer[1], szLang, charsmax(szLang), szBuffer, 1, ']');
		}
		else if( szBuffer[0] )
		{
			strbreak(szBuffer, szKey, charsmax(szKey), szTranslation, charsmax(szTranslation));
			iKey = GetLangTransKey(szKey);
			if( iKey != TransKey_Bad )
			{
				replace_all(szTranslation, charsmax(szTranslation), "!g", "^4");
				replace_all(szTranslation, charsmax(szTranslation), "!t", "^3");
				replace_all(szTranslation, charsmax(szTranslation), "!n", "^1");
				AddTranslation(szLang, iKey, szTranslation[2]);
			}
		}
	}
	
	fclose(fp);
	return 1;
}

stock create_cfg(const szName[], bool:bAutoCreate=true)
{
	new szFileName[32]
	new iLen = copy(szFileName, charsmax(szFileName), szName)
	if( iLen <= 4 || !equal(szFileName[iLen-4], ".cfg") )
	{
		add(szFileName, charsmax(szFileName), ".cfg")
	}

	new szConfigPath[96]
	get_localinfo("amxx_configsdir", szConfigPath, charsmax(szConfigPath))
	format(szConfigPath, charsmax(szConfigPath), "%s/%s", szConfigPath, szFileName)

	if( file_exists(szConfigPath) )
	{
		server_cmd("exec %s", szConfigPath)
		server_exec()
		return 1
	}
	else if( bAutoCreate )
	{
		new fp = fopen(szConfigPath, "wt")
		if( !fp )
		{
			return -1
		}
		new szPluginFileName[96], szPluginName[64], szAuthor[32], szVersion[32], szStatus[2]
		new iPlugin = get_plugin(-1, 
					szPluginFileName, charsmax(szPluginFileName), 
					szPluginName, charsmax(szPluginName), 
					szVersion, charsmax(szVersion), 
					szAuthor, charsmax(szAuthor), 
					szStatus, charsmax(szStatus) )

		server_print("Plugin id is %d", iPlugin)
		fprintf(fp, "; ^"%s^" configuration file^n", szPluginName)
		fprintf(fp, "; Author : ^"%s^"^n", szAuthor)
		fprintf(fp, "; Version : ^"%s^"^n", szVersion)
		fprintf(fp, "; File : ^"%s^"^n", szPluginFileName)

		new iMax, i, szCommand[64], iCommandAccess, szCmdInfo[128], szFlags[32]
		iMax = get_concmdsnum(-1, -1)
		fprintf(fp, "^n; Console Commands :^n")
		for(i=0; i<iMax; i++)
		{
			if( get_concmd_plid(i, -1, -1) == iPlugin )
			{
				get_concmd(i, 
						szCommand, charsmax(szCommand), 
						iCommandAccess, 
						szCmdInfo, charsmax(szCmdInfo), 
						-1, -1)
				get_flags(iCommandAccess, szFlags, charsmax(szFlags))
				fprintf(fp, "; %s | Access:^"%s^" | ^"%s^"^n", szCommand, szFlags, szCmdInfo)
			}
		}

		iMax = get_plugins_cvarsnum()
		new iTempId, iPcvar, szCvarName[256], szCvarValue[128]
		fprintf(fp, "^n; Cvars :^n")
		for(new i; i<iMax; i++)
		{
			get_plugins_cvar(i, szCvarName, charsmax(szCvarName), _, iTempId, iPcvar)
			if( iTempId == iPlugin )
			{
				get_pcvar_string(iPcvar, szCvarValue, charsmax(szCvarValue))
				fprintf(fp, "%s ^"%s^"^n", szCvarName, szCvarValue)
			}
		}

		fclose(fp)
	}
	return 0
}

/*
	@Drop user current weapon

	Index - Player Id
	WeaponId - Weapon Id to drop, If weaponId is '0' then will drop the current weapon from hand.

	#Return: NO RETURN
*/
stock drop_user_weapon( index, WeaponId=0 )
{
	if( is_user_alive(index) )
	{
		new szWeaponName[20];
		get_weaponname( WeaponId, szWeaponName, charsmax(szWeaponName) );

		new szWpIdszWeaponName[20];
		new iAmmo,iBpAmmo;
		new CurrentWeaponId = get_user_weapon( index, iAmmo, iBpAmmo );
		get_weaponname( CurrentWeaponId, szWpIdszWeaponName, charsmax(szWpIdszWeaponName) );

		engclient_cmd( index, "drop", WeaponId > 0 ? szWeaponName : szWpIdszWeaponName );			
	}
}

/* give user gravity */
stock set_player_gravity( id, iGravity )
{
	static GravityPointer;

	if( !GravityPointer ) 
		GravityPointer = get_cvar_pointer("sv_gravity");

	if( !is_user_alive( id ) || iGravity < 1 ) return;

	set_user_gravity( id, float( iGravity ) / float( get_pcvar_num( GravityPointer ) ) );
}
 

/*
	@Get the current weapon speed user is holding in hand.
	id - Player Id

	#Return: Integer Weapon Speed
*/
stock get_curweapon_speed( id ) 
{ 
	new iSpeed = 0;
	new iUnused;

	switch( get_user_weapon( id, iUnused, iUnused ) ) 
	{ 
		case CSW_KNIFE: iSpeed = 250; 
        	case CSW_SCOUT: iSpeed = 260; 
        	case CSW_USP: iSpeed = 250; 
        	case CSW_P228: iSpeed = 250; 
        	case CSW_HEGRENADE: iSpeed = 250; 
        	case CSW_XM1014: iSpeed = 240; 
       		case CSW_C4: iSpeed = 250; 
       		case CSW_AUG: iSpeed = 240; 
        	case CSW_SMOKEGRENADE: iSpeed = 250; 
        	case CSW_ELITE: iSpeed = 250; 
        	case CSW_FIVESEVEN: iSpeed = 250; 
        	case CSW_UMP45: iSpeed = 250; 
        	case CSW_SG550: iSpeed = 210; 
        	case CSW_GALIL: iSpeed = 240; 
        	case CSW_FAMAS: iSpeed = 240; 
       		case CSW_GLOCK18: iSpeed = 250; 
        	case CSW_AWP: iSpeed = 210; 
        	case CSW_MP5NAVY: iSpeed = 250; 
        	case CSW_M249: iSpeed = 220; 
        	case CSW_M3: iSpeed = 230; 
       		case CSW_M4A1: iSpeed = 230; 
        	case CSW_TMP: iSpeed = 250; 
        	case CSW_G3SG1: iSpeed = 210; 
        	case CSW_FLASHBANG: iSpeed = 250; 
        	case CSW_DEAGLE: iSpeed = 250; 
        	case CSW_SG552: iSpeed = 235; 
        	case CSW_AK47: iSpeed = 221; 
        	case CSW_P90: iSpeed = 245 
	} 	
	return iSpeed; 
}


/*
*
*
*
*
*	szDebugFileLocation is the location where the debug messages will be writed(wich file).
*
*
*/
static stock const szDebugFileLocation [] = "addons/amxmodx/data/Debugs.txt";

/*
*
*
*
*	Log an debug message, the message will be printed in all players chat/console, on the server consone and writed in the Debugs.txt
*
*	@iDebugLevel: is the level of debugging from 0 to 5 for debug_log() function.
*
*		0 - print a simple message to all players console from server.
*		1 - print a message to server console and to all players console from server.
*		2 - same as 1 plus printing a message in the Debugs.txt
*		3 - Same as 2 but all the third messages are formated with get_systime() function
*		4 - same as 3 but also with the get_mapname() format.
*		5 - Same at 4 but with Players Count format.
*
*
*
*	@szMessage[] - the message to send
*	@any - any parameter to format Message[]
*
*
*
*
*
*/
stock debug_log( iDebugLevel=0, const szMessage[] , any:... )
{
	static Frm[128];
	vformat( Frm, charsmax(Frm), szMessage, 3 );
	
	switch( iDebugLevel )
	{
		case 1:
		{
			server_print( "[DEBUG] %s", Frm );
			client_print( 0, print_console, "[DEBUG] %s", Frm );
		}
		case 2:
		{
			server_print( "[DEBUG] %s", Frm );
			client_print( 0, print_console, "[DEBUG] %s", Frm );

			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG] %s", Frm );
			write_file( szDebugFileLocation, buff );
		}

		case 3:
		{
			server_print( "[DEBUG, SysTime: %i] %s", get_systime(), Frm );
			client_print( 0, print_console, "[DEBUG, SysTime: %i] %s", get_systime(), Frm );

			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG, SysTime: %i] %s", get_systime(), Frm );
			write_file( szDebugFileLocation, buff );
		}
		case 4:
		{
			new szMap[32];
			get_mapname( szMap, charsmax(szMap) );

			server_print( "[DEBUG, SysTime: %i, Map: %s] %s", get_systime(), szMap, Frm );
			client_print( 0, print_console, "[DEBUG, SysTime: %i, Map: %s] %s", get_systime(), szMap, Frm );			

			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG, SysTime: %i, Map: %s] %s", get_systime(), szMap, Frm );
			write_file( szDebugFileLocation, buff );

		}

		case 5:
		{
			new szMap[32];
			get_mapname( szMap, charsmax(szMap) );

			server_print( "[DEBUG, SysTime: %i, Map: %s, Players: %i] %s", get_systime(), szMap, get_playersnum(), Frm );
			client_print( 0, print_console, "[DEBUG, SysTime: %i, Map: %s, Players: %i] %s", get_systime(), szMap, get_playersnum(), Frm );


			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG, SysTime: %i, Map: %s, Players: %i] %s", get_systime(), szMap, get_playersnum(), Frm );
			write_file( szDebugFileLocation, buff );
		}

		default:
		{
			client_print( 0, print_console, Frm );	
		}
	}
}