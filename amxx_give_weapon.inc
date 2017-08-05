#if defined _amxx_give_weapon_included
  #endinput
#endif
#define _amxx_give_weapon_included

#include <fakemeta>
#include <engine>


/* Give a weapon to a user, with specific Ammo,bpammo */
stock give_user_weapon( index , iWeaponTypeID , iClip=0 , iBPAmmo=0 , szWeapon[]="" , maxchars=0 )
{
	if ( !( CSW_P228 <= iWeaponTypeID <= CSW_P90 ) || ( iClip < 0 ) || ( iBPAmmo < 0 ) || !is_user_alive( index ) )
		return -1;
    
	new szWeaponName[ 20 ] , iWeaponEntity , bool:bIsGrenade;
    
	const GrenadeBits = ( ( 1 << CSW_HEGRENADE ) | ( 1 << CSW_FLASHBANG ) | ( 1 << CSW_SMOKEGRENADE ) | ( 1 << CSW_C4 ) );
    
	if ( ( bIsGrenade = bool:!!( GrenadeBits & ( 1 << iWeaponTypeID ) ) ) )
		iClip = clamp( iClip ? iClip : iBPAmmo , 1 );
    
	get_weaponname( iWeaponTypeID , szWeaponName , charsmax( szWeaponName ) );
    
	if ( ( iWeaponEntity = user_has_weapon( index , iWeaponTypeID ) ? find_ent_by_owner( -1 , szWeaponName , index ) : give_item( index , szWeaponName ) ) > 0 )
	{
		if ( iClip && !bIsGrenade )
			cs_set_weapon_ammo( iWeaponEntity , iClip );

		if ( iWeaponTypeID == CSW_C4 ) 
			cs_set_user_plant( index , 1 , 1 );
		else
			cs_set_user_bpammo( index , iWeaponTypeID , bIsGrenade ? iClip : iBPAmmo ); 
            
		if ( maxchars )
			copy( szWeapon , maxchars , szWeaponName[7] );
	}
	return iWeaponEntity;
} 
